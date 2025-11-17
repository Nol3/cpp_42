# Ejercicio 00: ScalarConverter - Guía Detallada de Implementación

## Descripción General
Este ejercicio requiere crear una clase que:
1. **Detecte** el tipo del string de entrada (char, int, float, double)
2. **Convierta** a un tipo base intermedio
3. **Convierta** explícitamente usando `static_cast` a los otros 3 tipos
4. **Valide y muestre** los resultados

---

## Paso 1: Análisis de tipos

### ¿Cómo identificar el tipo de entrada?

```
'a', 'z', '0'                  → char (entre comillas simples)
42, -100, 0                    → int (sin punto decimal ni 'f')
3.14f, -2.5f, +inff, nanf      → float (con 'f' al final)
3.14, -2.5, +inf, nan          → double (con punto decimal, sin 'f')
```

### Estrategia de detección

```cpp
bool isCharLiteral(const std::string &str) {
    // char: tiene exactamente 3 caracteres y empieza con '
    return str.length() == 3 && str[0] == '\'' && str[2] == '\'';
}

bool isFloatLiteral(const std::string &str) {
    // Termina en 'f' o 'F'
    return !str.empty() && (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F');
}

bool isIntLiteral(const std::string &str) {
    // No tiene punto decimal y no termina en 'f'
    return str.find('.') == std::string::npos && 
           !isFloatLiteral(str);
}

bool isDoubleLiteral(const std::string &str) {
    // Tiene punto decimal y no termina en 'f'
    return str.find('.') != std::string::npos && 
           !isFloatLiteral(str);
}
```

---

## Paso 2: Conversión del string al tipo base

### Convertir char
```cpp
char charValue = str[1];  // El carácter está entre las comillas
```

### Convertir int
```cpp
// Opción 1: stringstream
std::stringstream ss(str);
int intValue;
ss >> intValue;

// Opción 2: strtol
char *endPtr;
int intValue = std::strtol(str.c_str(), &endPtr, 10);

// Opción 3: atoi
int intValue = std::atoi(str.c_str());
```

### Convertir float
```cpp
// strtof (convierte a float)
char *endPtr;
float floatValue = std::strtof(str.c_str(), &endPtr);

// Casos especiales: ±inff, nanf
// strtof ya los maneja correctamente
```

### Convertir double
```cpp
// strtod (convierte a double)
char *endPtr;
double doubleValue = std::strtod(str.c_str(), &endPtr);

// Casos especiales: ±inf, nan
// strtod ya los maneja correctamente
```

---

## Paso 3: Conversión explícita a otros tipos

Una vez tenemos el valor en su tipo base, usamos `static_cast` para convertir a los otros:

```cpp
// Si el input era int
int intValue = 42;
char c = static_cast<char>(intValue);
float f = static_cast<float>(intValue);
double d = static_cast<double>(intValue);

// Si el input era float
float floatValue = 3.14f;
char c = static_cast<char>(floatValue);
int i = static_cast<int>(floatValue);
double d = static_cast<double>(floatValue);
```

---

## Paso 4: Validación y visualización

### Para char
```cpp
void printChar(char c) {
    // Si es displayable (ASCII 32-126)
    if (c >= 32 && c <= 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else if (isnan(c))  // Si viene de NaN
        std::cout << "char: impossible" << std::endl;
    else if (isinf(c))  // Si viene de Inf
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}
```

### Para int
```cpp
void printInt(int i) {
    // Si viene de NaN o Inf, no se puede convertir
    if (isnan(floatOriginal) || isinf(floatOriginal))
        std::cout << "int: impossible" << std::endl;
    else if (i > INT_MAX || i < INT_MIN)
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
}
```

### Para float y double
```cpp
void printFloat(float f) {
    // Mostrar con precisión correcta
    if (isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (isinf(f)) {
        if (f < 0)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: +inff" << std::endl;
    }
    else {
        // Mostrar el número con .0f si es necesario
        std::cout << std::fixed << std::setprecision(1) 
                  << "float: " << f << "f" << std::endl;
    }
}

void printDouble(double d) {
    if (isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (isinf(d)) {
        if (d < 0)
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: +inf" << std::endl;
    }
    else {
        std::cout << std::fixed << std::setprecision(1) 
                  << "double: " << d << std::endl;
    }
}
```

---

## Código completo de referencia (estructura)

```cpp
void ScalarConverter::convert(const std::string &input)
{
    // 1. DETECTAR TIPO
    bool isChar = isCharLiteral(input);
    bool isInt = isIntLiteral(input);
    bool isFloat = isFloatLiteral(input);
    bool isDouble = isDoubleLiteral(input);
    
    if (!isChar && !isInt && !isFloat && !isDouble) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    // 2. CONVERTIR A TIPO BASE
    char charVal = 0;
    int intVal = 0;
    float floatVal = 0.0f;
    double doubleVal = 0.0;

    if (isChar) {
        charVal = input[1];
        intVal = static_cast<int>(charVal);
        floatVal = static_cast<float>(charVal);
        doubleVal = static_cast<double>(charVal);
    }
    else if (isInt) {
        intVal = strtol(input.c_str(), nullptr, 10);
        charVal = static_cast<char>(intVal);
        floatVal = static_cast<float>(intVal);
        doubleVal = static_cast<double>(intVal);
    }
    else if (isFloat) {
        floatVal = strtof(input.c_str(), nullptr);
        charVal = static_cast<char>(floatVal);
        intVal = static_cast<int>(floatVal);
        doubleVal = static_cast<double>(floatVal);
    }
    else { // isDouble
        doubleVal = strtod(input.c_str(), nullptr);
        charVal = static_cast<char>(doubleVal);
        intVal = static_cast<int>(doubleVal);
        floatVal = static_cast<float>(doubleVal);
    }

    // 3. MOSTRAR RESULTADOS
    printChar(charVal);
    printInt(intVal);
    printFloat(floatVal);
    printDouble(doubleVal);
}
```

---

## Casos especiales a manejar

### NaN (Not a Number)
```
Input: nan  o  nanf
- char: impossible
- int: impossible
- float: nanf
- double: nan
```

### Infinito
```
Input: +inf, -inf, +inff, -inff
- char: impossible
- int: impossible
- float: +inff / -inff
- double: +inf / -inf
```

### Overflow
```
Input: 99999999999999999999999
Cuando se sobrepasa el rango de un tipo:
- Si int overflow: mostrar "impossible"
- Los casts para tipos más grandes manejan bien el overflow
```

---

## Funciones útiles de C++

```cpp
#include <cmath>
bool isnan(float/double value);
bool isinf(float/double value);

#include <limits>
INT_MAX, INT_MIN
FLOAT_MAX, FLOAT_MIN
...

#include <iomanip>
std::setprecision(n)
std::fixed
```

---

## Salida esperada

```bash
$ ./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

$ ./convert 42
char: '*'
int: 42
float: 42.0f
double: 42.0

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

$ ./convert +inff
char: impossible
int: impossible
float: +inff
double: +inf
```

