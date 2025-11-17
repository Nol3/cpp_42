# C++ Module 06 - Type Casts

## 📚 Estructura del Proyecto

```
cpp06/
├── README.md                 # Este archivo
├── GUIDE.md                  # Guía general sobre type casts
├── EX00_GUIDE.md            # Guía detallada Ejercicio 00
├── EX01_GUIDE.md            # Guía detallada Ejercicio 01
├── EX02_GUIDE.md            # Guía detallada Ejercicio 02
│
├── ex00/                     # Ejercicio 00: ScalarConverter
│   ├── Makefile
│   ├── main.cpp
│   ├── ScalarConverter.hpp
│   ├── ScalarConverter.cpp
│   └── convert               # (Ejecutable compilado)
│
├── ex01/                     # Ejercicio 01: Serializer
│   ├── Makefile
│   ├── main.cpp
│   ├── Data.hpp
│   ├── Serializer.hpp
│   ├── Serializer.cpp
│   └── serialize             # (Ejecutable compilado)
│
└── ex02/                     # Ejercicio 02: Identify
    ├── Makefile
    ├── main.cpp
    ├── Base.hpp   Base.cpp
    ├── A.hpp      A.cpp
    ├── B.hpp      B.cpp
    ├── C.hpp      C.cpp
    └── identify              # (Ejecutable compilado)
```

---

## 🎯 Resumen de los 3 Ejercicios

### **Ejercicio 00: ScalarConverter** (`static_cast`)
Convertir un string a 4 tipos escalares diferentes (char, int, float, double).

```bash
cd ex00
make
./convert 42.0f
# Output:
# char: '*'
# int: 42
# float: 42.0f
# double: 42.0
```

**Cast utilizado:** `static_cast` para conversiones entre tipos escalares

---

### **Ejercicio 01: Serializer** (`reinterpret_cast`)
Convertir un puntero a entero y viceversa.

```bash
cd ex01
make
./serialize
# Output:
# ✓ Pointers are equal!
```

**Cast utilizado:** `reinterpret_cast` para convertir puntero ↔ entero

---

### **Ejercicio 02: Identify** (`dynamic_cast`)
Identificar el tipo real de un objeto en una jerarquía de clases.

```bash
cd ex02
make
./identify
# Output:
# Testing with pointers:
# Object 1 is: A
# Object 2 is: B
# Object 3 is: C
# ...
```

**Cast utilizado:** `dynamic_cast` para RTTI (Runtime Type Information)

---

## 📖 Cómo leer las guías

1. **GUIDE.md** - Lee primero para entender los 4 tipos de casts
2. **EX00_GUIDE.md** - Cómo completar el Ejercicio 00 (paso a paso)
3. **EX01_GUIDE.md** - Cómo completar el Ejercicio 01 (paso a paso)
4. **EX02_GUIDE.md** - Cómo completar el Ejercicio 02 (paso a paso)

---

## 🏗️ Estado actual

### ✅ Completado
- [x] Estructura de directorios creada
- [x] Skeleton code para los 3 ejercicios
- [x] Makefiles listos
- [x] Compilación básica sin errores
- [x] Ejercicio 01 totalmente funcional (reinterpret_cast)
- [x] Ejercicio 02 totalmente funcional (dynamic_cast)
- [x] Documentación completa

### 📝 Pendiente de completar
- [ ] **Ejercicio 00:** Implementar el método `convert()` en ScalarConverter

---

## 🔧 Compilación rápida

```bash
# Compilar todo
for i in 0 1 2; do cd ex0$i && make && cd ..; done

# Limpiar todo
for i in 0 1 2; do cd ex0$i && make fclean && cd ..; done

# O uno por uno
cd ex00 && make && ./convert 42.0f
cd ../ex01 && make && ./serialize
cd ../ex02 && make && ./identify
```

---

## 📋 Reglas importantes

### ✅ Permitido
- Compilar con `-std=c++98`
- Usar headers estándar (`<iostream>`, `<string>`, `<cmath>`, etc.)
- Crear funciones helper
- Dividir código en múltiples archivos

### ❌ Prohibido
- C++11 y posteriores (solo C++98)
- Boost libraries
- `printf()`, `malloc()`, `free()`
- `using namespace std`
- `friend` keyword
- Containers (vector, list, map, etc.) - hasta Module 08
- `std::typeinfo` en Ejercicio 02

---

## 🧪 Próximos pasos

### 1. **Leer la documentación**
   Comienza con `GUIDE.md` para entender los concepts

### 2. **Entender cada ejercicio**
   Lee la guía específica (EX00_GUIDE.md, etc.)

### 3. **Completar Ejercicio 00**
   ScalarConverter es el más complejo:
   - Detectar tipo de input
   - Convertir a tipo base
   - Convertir explícitamente con `static_cast`
   - Validar y mostrar resultados

### 4. **Verificar compilación**
   ```bash
   c++ -Wall -Wextra -Werror -std=c++98 -o convert *.cpp
   ```

### 5. **Probar con ejemplos**
   ```bash
   ./convert 0
   ./convert 42.0f
   ./convert nan
   ./convert +inff
   ```

---

## 💡 Tips importantes

### Ejercicio 00
- Usa `strtol()`, `strtof()`, `strtod()` para parsear strings
- Incluye `<cmath>` para `isnan()` e `isinf()`
- Incluye `<limits>` para INT_MAX, INT_MIN, etc.
- Maneja casos especiales: NaN, Inf, overflow

### Ejercicio 01
- `uintptr_t` está en `<stdint.h>` (no `<cstdint>` para C++98)
- `reinterpret_cast` es seguro para puntero ↔ `uintptr_t`
- Verifica siempre: `deserialized == &original`

### Ejercicio 02
- **IMPORTANTE:** Base necesita destructor virtual para RTTI
- `dynamic_cast` retorna `nullptr` si falla (con punteros)
- Siempre inicializar seed de `rand()` en `main()`
- No olvidar `delete` en los bucles

---

## 📞 Compilación con todos los flags

Usa siempre los flags recomendados:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

**Significado:**
- `-Wall`: Habilita casi todos los warnings
- `-Wextra`: Warnings adicionales
- `-Werror`: Convierte warnings en errores
- `-std=c++98`: Usa estándar C++98

---

## ✨ Estructura de archivo típica

### Header (.hpp)
```cpp
#ifndef CLASSNAME_HPP
#define CLASSNAME_HPP

#include <iostream>

class ClassName {
private:
    // Constructores privados para clases no instanciables
    ClassName();
    ~ClassName();
    ClassName(const ClassName &);
    ClassName &operator=(const ClassName &);

public:
    static void method(void);
};

#endif
```

### Implementación (.cpp)
```cpp
#include "ClassName.hpp"

// Implementar métodos aquí

void ClassName::method(void) {
    // ...
}
```

---

## 📚 Referencias de C++ útiles

- `std::string` - Manejo de strings
- `std::stringstream` - Parsing de strings
- `std::cout`, `std::cerr` - Output
- `std::iomanip` - Formateo de números
- `<cmath>` - Funciones matemáticas
- `<limits>` - Límites de tipos

---

## ¿Preguntas?

- Revisa la guía correspondiente a tu ejercicio
- Busca en `EX0X_GUIDE.md` los errores comunes
- Verifica la compilación con los flags correctos

**¡Éxito con el módulo!** 🚀

