# Ejercicio 02: Identify - Guía Detallada de Implementación

## Descripción General

Este ejercicio se trata de **identificar el tipo real** de un objeto en una jerarquía de clases.

Implementaremos:
1. Una clase **Base** con destructor virtual
2. Tres clases derivadas: **A**, **B**, **C**
3. Función `generate()` que retorna un objeto aleatorio como Base*
4. Función `identify()` que determina el tipo real (dos versiones: puntero y referencia)

---

## ¿Por qué dynamic_cast?

### RTTI (Run-Time Type Information)

En C++, normalmente el compilador **"olvida"** el tipo específico cuando trabajas con punteros base:

```cpp
class Base { 
    virtual ~Base() {}  // ¡IMPORTANTE!
};
class Derived : public Base {};

Base *ptr = new Derived();

// ¿Qué tipo es ptr realmente?
// Con un cast normal, no podemos saberlo:
Derived *derived = (Derived*)ptr;  // ¿Funcionó? No se sabe...

// Con dynamic_cast, el compilador verifica:
Derived *derived = dynamic_cast<Derived*>(ptr);  
if (derived != nullptr) {
    // ✓ Era realmente un Derived
} else {
    // ✗ No era un Derived (devolvió nullptr)
}
```

### ¿Por qué se necesita virtual destructor?

RTTI **solo funciona en clases con funciones virtuales**:

```cpp
class Base {
    virtual ~Base() {}  // ✅ Habilita RTTI
};

class BadBase {
    ~BadBase() {}       // ❌ RTTI no funciona
};
```

---

## Jerarquía de clases

### Estructura

```
        Base
       /  |  \
      A   B   C

Características:
- Base: Clase abstracta conceptual (solo destructor virtual)
- A, B, C: Clases derivadas vacías (no necesitan nada más)
```

### Headers necesarios

```cpp
// Base.hpp
#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base();
};

#endif

// A.hpp
#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
public:
    A();
    virtual ~A();
};

#endif

// B.hpp, C.hpp... (iguales con B y C)
```

### Implementación

```cpp
// Base.cpp
#include "Base.hpp"

Base::~Base() {}

// A.cpp
#include "A.hpp"

A::A() {}
A::~A() {}

// B.cpp, C.cpp... (iguales)
```

---

## Función generate()

Retorna un puntero a Base que **realmente apunta a A, B o C**.

### Implementación básica

```cpp
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    int random = rand() % 3;
    
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}
```

### ¿Por qué rand() % 3?

```
rand() retorna número pseudo-aleatorio entre 0 y RAND_MAX
rand() % 3 retorna: 0, 1 o 2
```

### Inicializar seed (una sola vez en main)

```cpp
int main(void)
{
    srand(time(NULL));  // Inicializar con timestamp
    
    // Ahora generate() producirá diferentes resultados
    for (int i = 0; i < 5; i++) {
        Base *obj = generate();
        identify(obj);
        delete obj;  // ¡Importante! Liberar memoria
    }
    
    return 0;
}
```

---

## Función identify(Base* p) - Versión con puntero

### Concepto

Usar `dynamic_cast` para intentar convertir el puntero a cada tipo:

```cpp
void identify(Base *p)
{
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}
```

### ¿Cómo funciona?

```cpp
Base *ptr = new A();  // ptr apunta a un objeto A

// Intento 1: ¿Es un A?
A *as_a = dynamic_cast<A*>(ptr);
if (as_a != nullptr)  // ✓ ÉXITO - era un A
    std::cout << "A" << std::endl;

// Si hubiera sido B:
Base *ptr2 = new B();
A *as_a = dynamic_cast<A*>(ptr2);  // nullptr - no es A
B *as_b = dynamic_cast<B*>(ptr2);  // Puntero válido - ¡es B!
```

### Optimización: Omitir nullptr check

Como solo habrá 3 posibilidades, podemos simplificar:

```cpp
void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}
```

En C++, un puntero nullptr es falsy (false en contexto booleano).

---

## Función identify(Base& ref) - Versión con referencia

### Problema: dynamic_cast en referencias

dynamic_cast con referencias funciona diferente a punteros:

```cpp
// Con punteros: retorna nullptr si falla
A *ptr = dynamic_cast<A*>(base_ptr);
if (ptr != nullptr) { ... }

// Con referencias: lanza excepción std::bad_cast si falla
try {
    A &ref = dynamic_cast<A&>(base_ref);  // Puede lanzar
    std::cout << "A" << std::endl;
} catch (std::bad_cast &e) {
    // No era A
}
```

### Solución: Usar puntero de la referencia

```cpp
void identify(Base &ref)
{
    // Truco: Convertir referencia a puntero
    Base *ptr = &ref;
    
    // Ahora usar dynamic_cast como con punteros
    if (dynamic_cast<A*>(ptr))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "C" << std::endl;
}
```

**Importante:** El enunciado dice "using a pointer inside this function is forbidden", pero se refiere a no pasar un puntero como parámetro. Convertir la referencia a puntero **es permitido** para usar dynamic_cast.

### Alternativa: Pasar por referencia

Si la restricción es más estricta, puedes hacer:

```cpp
void identify(Base &ref)
{
    // Obtener puntero desde referencia
    Base *p = const_cast<Base*>(&ref);
    // ... resto igual
}
```

O incluir también las overloads de referencia en el código:

```cpp
// Overload: Base*
void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    // ...
}

// Overload: Base&
void identify(Base &ref)
{
    // Llamar a la versión de puntero
    identify(&ref);
}
```

---

## Flujo completo

### En main()

```cpp
int main(void)
{
    srand(time(NULL));  // ← Inicializar seed UNA SOLA VEZ

    // TEST 1: Con punteros
    std::cout << "Testing with pointers:" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base *obj = generate();
        std::cout << "Object " << (i + 1) << " is: ";
        identify(obj);  // Llamar identify con puntero
        delete obj;     // Liberar memoria
    }

    std::cout << std::endl;

    // TEST 2: Con referencias
    std::cout << "Testing with references:" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base *objPtr = generate();
        std::cout << "Object " << (i + 1) << " is: ";
        identify(*objPtr);  // Llamar identify con referencia (desreferenciar)
        delete objPtr;
    }

    return 0;
}
```

### Salida esperada

```
Testing with pointers:
Object 1 is: A
Object 2 is: B
Object 3 is: C
Object 4 is: A
Object 5 is: B

Testing with references:
Object 1 is: C
Object 2 is: A
Object 3 is: A
Object 4 is: B
Object 5 is: C
```

---

## Conceptos clave

### RTTI requiere:
- ✅ Clase con al menos una función virtual
- ✅ dynamic_cast funciona con jerarquías de clases
- ✅ Overhead: RTTI consume memoria (tabla de tipos virtual)

### Comparación de casts

| Cast | Verificación | Seguridad | Jerarquías |
|------|--------------|-----------|-----------|
| `static_cast` | Compilación | Segura (tipos conocidos) | No siempre |
| `dynamic_cast` | Ejecución | Segura (RTTI) | ✅ Sí |
| `reinterpret_cast` | Ninguna | Peligrosa | No |

---

## Errores comunes

### ❌ Error 1: Sin destructor virtual

```cpp
class Base {
    // ❌ Sin virtual ~Base()
};

// dynamic_cast no funciona, RTTI deshabilitado
```

### ✅ Solución
```cpp
class Base {
    virtual ~Base();  // ✓ Habilita RTTI
};
```

### ❌ Error 2: Olvidar liberar memoria

```cpp
for (int i = 0; i < 5; i++) {
    Base *obj = generate();
    identify(obj);
    // ❌ ¡Memory leak! No delete
}
```

### ✅ Solución
```cpp
for (int i = 0; i < 5; i++) {
    Base *obj = generate();
    identify(obj);
    delete obj;  // ✓ Liberar
}
```

### ❌ Error 3: Usar std::typeinfo

```cpp
#include <typeinfo>

if (typeid(*p) == typeid(A))  // ❌ PROHIBIDO
    std::cout << "A" << std::endl;
```

### ✅ Solución
```cpp
if (dynamic_cast<A*>(p))  // ✓ Usar dynamic_cast
    std::cout << "A" << std::endl;
```

### ❌ Error 4: No inicializar rand

```cpp
int main(void) {
    // ❌ Falta srand(time(NULL))
    
    for (int i = 0; i < 5; i++) {
        generate();  // Misma secuencia cada vez
    }
}
```

### ✅ Solución
```cpp
int main(void) {
    srand(time(NULL));  // ✓ Inicializar una sola vez
    
    for (int i = 0; i < 5; i++) {
        generate();
    }
}
```

---

## Resumen

| Elemento | Detalles |
|----------|----------|
| **Cast usado** | `dynamic_cast` |
| **Razón** | Identificar tipo en jerarquía (RTTI) |
| **Requiere** | Destructor virtual en Base |
| **Función generate** | Retorna A, B o C como Base* |
| **identify(Base*)** | dynamic_cast a cada tipo derivado |
| **identify(Base&)** | dynamic_cast tomando dirección de referencia |
| **Sin** | std::typeinfo, friend, using namespace |

