# Ejercicio 01: Serializer - Guía Detallada de Implementación

## Descripción General

Serialización es el proceso de convertir un objeto a bytes para almacenamiento o transmisión.

En este caso, vamos a:
1. Convertir un **puntero** a un **número entero** (`uintptr_t`)
2. Convertir ese número de vuelta al **puntero original**
3. Verificar que son exactamente el mismo puntero

---

## ¿Por qué reinterpret_cast?

### Memoria en C++

Todo en la memoria tiene una **dirección**. Un puntero es simplemente ese número de dirección:

```
Variable x:     [Dirección: 0x7fff1234] → [Valor: 42]
                Puntero int* px = &x;      px contiene: 0x7fff1234
```

### reinterpret_cast vs static_cast

```cpp
int x = 42;
int* ptr = &x;

// static_cast: Intenta una conversión segura
// int* a int es INCOMPATIBLE - ¡error de compilación!
int value = static_cast<int>(ptr);  // ❌ ERROR

// reinterpret_cast: "Confío en ti programador, reinterpreta los bits"
uintptr_t address = reinterpret_cast<uintptr_t>(ptr);  // ✅ OK
// address contiene: 140734873220140 (el valor de 0x7fff1234 en decimal)
```

---

## Estructura Data

Debe tener **datos no vacíos**:

```cpp
struct Data {
    int number;           // Miembro 1
    std::string name;     // Miembro 2 (no-POD, requiere constructor/destructor)
    double value;         // Miembro 3
};
```

**Importante:** `std::string` requiere que el compilador entienda su constructores/destructores, por eso es una buena prueba de que la serialización preserva correctamente la dirección.

---

## Implementación de Serializer

### Clase Serializer (no instantiable)

```cpp
class Serializer {
private:
    // Privado para que no se pueda instanciar
    Serializer();
    ~Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);

public:
    // Métodos estáticos públicos
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};
```

### Método serialize()

```cpp
uintptr_t Serializer::serialize(Data *ptr)
{
    // Reinterpreta el puntero como un número entero
    return reinterpret_cast<uintptr_t>(ptr);
    
    // Ejemplo:
    // Si ptr = 0x7fff1234
    // Retorna: 140734873220140 (decimal equivalente)
}
```

### Método deserialize()

```cpp
Data *Serializer::deserialize(uintptr_t raw)
{
    // Reinterpreta el número entero de vuelta como puntero
    return reinterpret_cast<Data *>(raw);
    
    // Ejemplo:
    // Si raw = 140734873220140
    // Retorna: 0x7fff1234 (como puntero)
}
```

---

## Implementación del programa de prueba

### Lógica básica

```cpp
int main(void)
{
    // 1. CREAR un objeto Data con datos
    Data originalData;
    originalData.number = 42;
    originalData.name = "My Data";
    originalData.value = 3.14159;

    std::cout << "Original address: " << &originalData << std::endl;

    // 2. SERIALIZAR (convertir puntero a número)
    uintptr_t serializedValue = Serializer::serialize(&originalData);
    
    std::cout << "Serialized (as int): " << serializedValue << std::endl;

    // 3. DESERIALIZAR (convertir número de vuelta a puntero)
    Data *recoveredPtr = Serializer::deserialize(serializedValue);

    std::cout << "Recovered address: " << recoveredPtr << std::endl;

    // 4. VERIFICAR que son el mismo
    if (recoveredPtr == &originalData) {
        std::cout << "✓ SUCCESS: Pointers are identical!" << std::endl;
        std::cout << "  Original data intact: " << recoveredPtr->name << std::endl;
    } else {
        std::cout << "✗ FAILURE: Pointers don't match!" << std::endl;
    }

    return 0;
}
```

---

## Conceptos clave

### uintptr_t

Es un tipo entero que **puede almacenar cualquier puntero**:

```cpp
#include <stdint.h>  // Para C++98

uintptr_t = unsigned integer pointer type
// En sistemas de 64 bits: equivalente a unsigned long long (64 bits)
// En sistemas de 32 bits: equivalente a unsigned int (32 bits)
```

### Garantías de reinterpret_cast

✅ **Garantizado:**
- `reinterpret_cast<uintptr_t>(ptr)` → obtiene la dirección como número
- `reinterpret_cast<Data*>(addr)` → recupera el puntero original

❌ **NO garantizado:**
- Convertir entre tipos de puntero diferentes (aunque a menudo funciona)
- Convertir punteros entre máquinas diferentes
- Portabilidad (uintptr_t puede ser diferente tamaño)

---

## Flujo completo

```
Memoria Stack:
┌─────────────────┐
│ Data object     │  Dirección: 0x7fff1234
│  - number: 42   │  
│  - name: "..."  │
│  - value: 3.14  │
└─────────────────┘
        ↑
        │ Puntero: 0x7fff1234 (dirección en decimal: 140734873220140)
        │
    serialize()
        │ reinterpret_cast<uintptr_t>(ptr)
        ↓
    uintptr_t = 140734873220140
        │ 
    (podría guardarse en archivo, transmitirse, etc.)
        │
   deserialize()
        │ reinterpret_cast<Data*>(uintptr_t)
        ↓
    Puntero de vuelta: 0x7fff1234
        │
        └─→ ¡Apunta al mismo objeto!
```

---

## Ejemplos de ejecución

### Ejecución típica

```
=== Serializer Test ===
Original Data:
  number: 42
  name: Test Data
  value: 3.14
  address: 0x7ffda2e8c7d0

Serialized value: 140734161916880

Deserialized Data:
  number: 42
  name: Test Data
  value: 3.14
  address: 0x7ffda2e8c7d0

✓ Pointers are equal!
```

### Puntos importantes en la salida

1. Las direcciones originales y recuperadas son **idénticas**
2. El valor serializado es simplemente la dirección en decimal
3. Los datos dentro de la estructura se mantienen intactos
4. Los punteros se pueden comparar directamente con `==`

---

## Errores comunes

### ❌ Error 1: Serializar variables locales

```cpp
{
    Data localData;
    Data *ptr = &localData;
    uintptr_t addr = Serializer::serialize(ptr);
} // localData se destruye aquí!

// Después deserializar apunta a memoria inválida
Data *bad = Serializer::deserialize(addr);  // ⚠️ Use After Free!
```

### ✅ Solución
Solo serializar objetos que persistirán más allá de la deserialización.

### ❌ Error 2: Olvidar include guards

```cpp
// Data.hpp sin guards
struct Data { ... };

// Incluir dos veces causa redefinición
```

### ✅ Solución
```cpp
#ifndef DATA_HPP
#define DATA_HPP
// contenido
#endif
```

### ❌ Error 3: No hacer Serializer no-instantiable

```cpp
Serializer s;  // ¡Esto debería ser un error!
```

### ✅ Solución
Constructor privado + C++98 no copia implícita.

---

## Resumen

| Aspecto | Detalles |
|---------|----------|
| **Cast usado** | `reinterpret_cast<>` |
| **Razón** | Convertir entre puntero e entero |
| **Función serialize** | Puntero → uintptr_t |
| **Función deserialize** | uintptr_t → Puntero |
| **Verificación clave** | `deserialized == &original` |

