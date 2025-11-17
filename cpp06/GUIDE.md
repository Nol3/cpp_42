# C++ Module 06 - Type Casts
## Guía Completa paso a paso

---

## 📋 Índice
1. [Introducción a Type Casts](#introducción)
2. [Ejercicio 00 - ScalarConverter](#ejercicio-00)
3. [Ejercicio 01 - Serializer](#ejercicio-01)
4. [Ejercicio 02 - Identify](#ejercicio-02)

---

## Introducción

Este módulo se enfoca en los **4 tipos de casts en C++**:

### 1. **static_cast<type>(value)**
```cpp
int a = 42;
double d = static_cast<double>(a);  // Convierte int a double
float f = static_cast<float>(a);    // Convierte int a float
char c = static_cast<char>(a);      // Convierte int a char
```

**Características:**
- ✅ Conversión compilada y verificada por el compilador
- ✅ Usada para conversiones implícitas y explícitas seguras
- ✅ Los tipos deben ser relacionados
- ❌ No funciona para conversión de punteros de diferentes tipos

### 2. **dynamic_cast<type>(value)**
```cpp
class Base { virtual ~Base() {} };
class Derived : public Base {};

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);  // Conversión segura
if (d != nullptr) {
    // Es realmente un Derived
}
```

**Características:**
- ✅ Conversión segura en jerarquías de clases (RTTI)
- ✅ Requiere que las clases tengan funciones virtuales
- ✅ Retorna nullptr si falla (en punteros)
- ✅ Lanza bad_cast en referencias (excepción)
- ❌ Sobrecarga de rendimiento

### 3. **reinterpret_cast<type>(value)**
```cpp
Data* ptr = new Data();
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);  // Puntero a entero
Data* recovered = reinterpret_cast<Data*>(raw);   // Entero a puntero
```

**Características:**
- ✅ Reinterpreta bytes sin conversión real
- ⚠️ Muy peligroso - responsabilidad del programador
- ✅ Usado para serialización de punteros
- ✅ Permite conversión entre punteros diferentes

### 4. **const_cast<type>(value)**
```cpp
const int x = 5;
int* ptr = const_cast<int*>(&x);  // Quita constancia
```

---

## Ejercicio 00: ScalarConverter

### Objetivo
Crear una clase que convierte un string a 4 tipos escalares: `char`, `int`, `float`, `double`.

### Pasos de implementación

#### Paso 1: Detectar el tipo de entrada
Analizar el string para determinar si es:
- Un carácter simple: `'a'`, `'c'`
- Un entero: `42`, `-100`
- Un float: `3.14f`, `-2.5f`, `+inff`, `-inff`, `nanf`
- Un double: `3.14`, `-2.5`, `+inf`, `-inf`, `nan`

#### Paso 2: Convertir a tipo base
```cpp
// Para int
std::stringstream ss(str);
int intValue;
ss >> intValue;

// Para float
float floatValue = std::strtof(str.c_str(), nullptr);

// Para double
double doubleValue = std::strtod(str.c_str(), nullptr);
```

#### Paso 3: Convertir a otros tipos con static_cast
```cpp
char c = static_cast<char>(intValue);
int i = static_cast<int>(floatValue);
float f = static_cast<float>(doubleValue);
double d = static_cast<double>(intValue);
```

#### Paso 4: Validar y mostrar resultados
- Verificar si el valor es displayable (para char)
- Verificar si hay overflow
- Mostrar los resultados en el formato especificado

**Ejemplo de ejecución:**
```
$ ./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

$ ./convert nan
char: impossible
int: impossible
float: nanf
double: nan
```

---

## Ejercicio 01: Serializer

### Objetivo
Convertir punteros a enteros y viceversa para "serializar" datos.

### ¿Por qué usar reinterpret_cast?
Los punteros son direcciones de memoria (números). `reinterpret_cast` nos permite:
- Convertir un puntero a `uintptr_t` (entero de tamaño de puntero)
- Convertir ese entero de vuelta al puntero original

### Implementación

#### Paso 1: Crear estructura Data
```cpp
struct Data {
    int number;
    std::string name;
    double value;
};
```

#### Paso 2: Implementar serialize()
```cpp
static uintptr_t serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
```

#### Paso 3: Implementar deserialize()
```cpp
static Data *deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
```

#### Paso 4: Verificar
```cpp
Data data;
data.number = 42;

uintptr_t raw = Serializer::serialize(&data);
Data* recovered = Serializer::deserialize(raw);

assert(recovered == &data);  // ✓ Los punteros son iguales
```

---

## Ejercicio 02: Identify

### Objetivo
Identificar el tipo real de un objeto en una jerarquía de clases.

### ¿Por qué usar dynamic_cast?
`dynamic_cast` es el único cast que puede verificar el tipo real de un objeto en tiempo de ejecución (RTTI).

### Implementación

#### Paso 1: Crear jerarquía de clases
```cpp
class Base {
public:
    virtual ~Base();  // ¡IMPORTANTE! Necesita ser virtual
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
```

#### Paso 2: Función generate()
Retorna un puntero a Base apuntando a A, B o C aleatoriamente.

```cpp
Base *generate(void) {
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}
```

#### Paso 3: Función identify(Base* p)
Usa `dynamic_cast` para verificar el tipo.

```cpp
void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}
```

#### Paso 4: Función identify(Base& ref)
Versión con referencias (sin punteros).

```cpp
void identify(Base &ref) {
    if (dynamic_cast<A *>(&ref))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(&ref))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(&ref))
        std::cout << "C" << std::endl;
}
```

**Nota importante:** Aunque trabajamos con referencias, usamos `dynamic_cast<A*>(&ref)` para evitar excepciones.

---

## 📝 Notas Importantes

### ✅ Lo que DEBE cumplir
- [ ] Compilar con `-Wall -Wextra -Werror -std=c++98`
- [ ] Usar el tipo de cast correcto para cada ejercicio
- [ ] No crear memory leaks (usar `delete`)
- [ ] Las clases no instanciables deben tener constructor privado
- [ ] Include guards en todos los headers
- [ ] No usar `using namespace`
- [ ] No usar STL containers

### ⚠️ Restricciones importantes
- Ejercicio 00: Detectar tipos y convertir correctamente
- Ejercicio 01: Los punteros desserializados DEBEN ser iguales a los originales
- Ejercicio 02: ¡No usar `std::typeinfo`!

---

## 🧪 Compilación y Ejecución

```bash
# Ejercicio 00
cd ex00
make
./convert 42.0f
./convert nan
make clean

# Ejercicio 01
cd ../ex01
make
./serialize
make clean

# Ejercicio 02
cd ../ex02
make
./identify
make clean
```

---

## 🎯 Resumen de Type Casts a Usar

| Ejercicio | Cast | Razón |
|-----------|------|-------|
| **Ex00** | `static_cast` | Conversión entre tipos escalares |
| **Ex01** | `reinterpret_cast` | Puntero ↔ Entero |
| **Ex02** | `dynamic_cast` | Identificar tipo en jerarquía |

