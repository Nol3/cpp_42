# Quick Reference: Type Casts en C++ Module 06

## 🎯 Tabla de Referencia Rápida

| Ejercicio | Cast | Propósito | Archivos |
|-----------|------|-----------|----------|
| **Ex00** | `static_cast<>` | Convertir entre tipos escalares | `ScalarConverter.*` |
| **Ex01** | `reinterpret_cast<>` | Puntero ↔ Entero | `Serializer.*` |
| **Ex02** | `dynamic_cast<>` | RTTI en jerarquías | `Base.*, A.*, B.*, C.*` |

---

## 📌 Los 4 Casts Explicados en 30 segundos

### 1️⃣ `static_cast<type>(value)`
```cpp
// Conversión segura, verificada en compilación
int a = 42;
double b = static_cast<double>(a);  // OK: 42.0
float c = static_cast<float>(a);    // OK: 42.0f
```
**Cuándo:** Convertir entre tipos relacionados (int→double→char)

### 2️⃣ `dynamic_cast<type>(pointer)`
```cpp
// Conversión SEGURA en runtime (requiere virtual function)
Base *ptr = new Derived();
Derived *d = dynamic_cast<Derived*>(ptr);  // OK si es Derived
if (d == nullptr) { /* No era Derived */ }
```
**Cuándo:** Saber el tipo real de un objeto en jerarquía

### 3️⃣ `reinterpret_cast<type>(value)`
```cpp
// Reinterpretar BYTES sin conversión - ¡PELIGROSO!
Data *ptr = &data;
uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);  // Dirección como número
```
**Cuándo:** Serializar punteros, acceso bajo nivel

### 4️⃣ `const_cast<type>(value)`
```cpp
// Agregar/quitar const
const int x = 5;
int *p = const_cast<int*>(&x);  // Quita const
```
**Cuándo:** Raramente en este módulo

---

## 🔧 Implementación Rápida

### Exercise 00: ScalarConverter
```cpp
void ScalarConverter::convert(const std::string &input) {
    // 1. Detectar tipo
    if (es_char) {
        charVal = ...;
        intVal = static_cast<int>(charVal);
        floatVal = static_cast<float>(charVal);
        doubleVal = static_cast<double>(charVal);
    }
    // ... similar para int, float, double
    
    // 2. Mostrar con formato correcto
    printChar(charVal);
    printInt(intVal);
    printFloat(floatVal);
    printDouble(doubleVal);
}
```

### Exercise 01: Serializer
```cpp
// Simplísimo - reinterpret_cast es el corazón
uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

// ✓ HECHO!
```

### Exercise 02: Identify
```cpp
// dynamic_cast en acción
void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// ✓ HECHO!
```

---

## 🚀 Comandos de Compilación y Ejecución

```bash
# Ex01 - Serializer
cd cpp06/ex01 && make && ./serialize

# Ex02 - Identify  
cd cpp06/ex02 && make && ./identify

# Ex00 - ScalarConverter (cuando esté listo)
cd cpp06/ex00 && make
./convert 42          # int
./convert 42.0f       # float
./convert 3.14        # double
./convert 'a'         # char
./convert nan         # special
./convert +inff       # special
```

---

## 🎓 Conceptos Clave

### static_cast
```
int → double → float → char
           ↑
     SIEMPRE SEGURO

int a = 42;
double d = static_cast<double>(a);  // ✓ Permitido
int* p = static_cast<int*>(d);      // ✗ Error
```

### dynamic_cast
```
       Base (virtual ~Base())
      /  |  \
     A   B   C
     
Base *ptr;
if (dynamic_cast<A*>(ptr)) { /* ES A */ }
else if (dynamic_cast<B*>(ptr)) { /* ES B */ }
// ✓ RTTI magic happens here
```

### reinterpret_cast
```
Data *ptr = &data;           // Dirección memoria
   ↓ reinterpret_cast<uintptr_t>
uintptr_t addr = 0x7fff...;  // Número
   ↓ reinterpret_cast<Data*>
Data *recovered = &data;     // MISMO puntero

GARANTÍA: recovered == ptr  ✓
```

---

## 📋 Checklist de Implementación

### Ejercicio 00 (Pendiente)
- [ ] Detectar tipo de input (char/int/float/double)
- [ ] Parsear string a tipo base
- [ ] Usar static_cast para conversiones
- [ ] Validar overflow
- [ ] Formatear salida correctamente
- [ ] Compilar con -Wall -Wextra -Werror -std=c++98

### Ejercicio 01 (✓ Done)
- [x] Clase Serializer no instantiable
- [x] reinterpret_cast en serialize()
- [x] reinterpret_cast en deserialize()
- [x] Data struct con miembros
- [x] Test: pointers iguales

### Ejercicio 02 (✓ Done)
- [x] Clase Base con virtual ~Base()
- [x] Clases A, B, C herdan de Base
- [x] generate() retorna A/B/C aleatoriamente
- [x] identify(Base*) usa dynamic_cast
- [x] identify(Base&) funciona con referencias
- [x] random seed en main()
- [x] delete en bucles

---

## ⚡ Errors Comunes y Soluciones

### Error: "cannot dynamic_cast"
```cpp
// ✗ INCORRECTO: Sin función virtual
class Base { };  // ❌ Falta destructor virtual

// ✓ CORRECTO:
class Base {
public:
    virtual ~Base();  // ✓ Habilita RTTI
};
```

### Error: "unknown type uintptr_t"
```cpp
// ✗ INCORRECTO: C++11 header
#include <cstdint>  // ❌ No en C++98

// ✓ CORRECTO: C++98 header
#include <stdint.h>  // ✓ Funciona en C++98
```

### Error: "memory leak"
```cpp
// ✗ INCORRECTO:
Base *obj = generate();
identify(obj);
// ❌ Falta delete

// ✓ CORRECTO:
Base *obj = generate();
identify(obj);
delete obj;  // ✓ Liberar
```

### Error: "random siempre igual"
```cpp
// ✗ INCORRECTO: Sin inicializar
for (int i = 0; i < 5; i++)
    generate();  // ❌ Misma secuencia

// ✓ CORRECTO:
srand(time(NULL));  // ✓ Una sola vez
for (int i = 0; i < 5; i++)
    generate();
```

---

## 💡 Tips de Implementación

### Ex00: Parsear Strings
```cpp
// Detectar tipo
bool isFloat(const std::string &s) {
    return s[s.length()-1] == 'f';
}

// Parsear a tipo base
int intVal = std::strtol(str.c_str(), nullptr, 10);
float floatVal = std::strtof(str.c_str(), nullptr);
double doubleVal = std::strtod(str.c_str(), nullptr);

// Validar especiales
bool isnan(float v);    // Requiere <cmath>
bool isinf(double v);   // Requiere <cmath>
```

### Ex01: Verificación
```cpp
// Siempre verificar que la deserialización es correcta:
assert(Serializer::deserialize(
    Serializer::serialize(&data)
) == &data);
```

### Ex02: Identificación
```cpp
// Patrón idiomático con dynamic_cast
Base *ptr = generate();

if (dynamic_cast<A*>(ptr))
    type = "A";
else if (dynamic_cast<B*>(ptr))
    type = "B";
else
    type = "C";

delete ptr;
```

---

## 🎯 Flujo de Resolución

```
┌─────────────────────────────┐
│  Leer GUIDE.md + README.md  │
└──────────────┬──────────────┘
               ↓
┌─────────────────────────────┐
│  Ejecutar ex01 y ex02       │
│  (ya están completos)       │
└──────────────┬──────────────┘
               ↓
┌─────────────────────────────┐
│  Leer EX00_GUIDE.md         │
│  (detallado paso a paso)    │
└──────────────┬──────────────┘
               ↓
┌─────────────────────────────┐
│  Implementar ScalarConverter│
│  1. Detectar tipo           │
│  2. Parsear string          │
│  3. static_cast             │
│  4. Validar y mostrar       │
└──────────────┬──────────────┘
               ↓
┌─────────────────────────────┐
│  Compilar y probar:         │
│  make && ./convert <test>   │
└──────────────┬──────────────┘
               ↓
┌─────────────────────────────┐
│  HECHO! 🚀                  │
└─────────────────────────────┘
```

---

## 📚 Archivos Documentación

```
cpp06/
├── README.md         ← Empieza aquí
├── GUIDE.md          ← Conceptos de casts
├── PROJECT_OVERVIEW.txt  ← Este archivo
├── EX00_GUIDE.md     ← Cómo hacer ex00
├── EX01_GUIDE.md     ← Referencia ex01
└── EX02_GUIDE.md     ← Referencia ex02
```

---

## ✅ Validación Final

```bash
# Compilación con flags estrictos
c++ -Wall -Wextra -Werror -std=c++98 -o program *.cpp

# Ejecución de pruebas
./program test_case

# Verificación de memory leaks (si tienes valgrind)
valgrind ./program test_case
```

---

**Última actualización:** Nov 17, 2025
**Estado:** Ex01 ✓ Ex02 ✓ Ex00 (skeleton ready)
**Próximo:** Implementar Exercise 00 - ScalarConverter

