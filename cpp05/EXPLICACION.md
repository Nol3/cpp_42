# 🎓 Explicación Paso a Paso - C++ Module 05

## 📖 Introducción a Excepciones en C++

Las excepciones permiten manejar errores de forma elegante sin usar códigos de retorno.

### ¿Qué es una excepción?

```cpp
try {
    // Código que puede lanzar una excepción
    if (grado < 1)
        throw GradeTooHighException();
}
catch (std::exception& e) {
    // Manejar el error
    std::cout << "Error: " << e.what() << std::endl;
}
```

---

## 🏗️ EJERCICIO 00 - Bureaucrat

### Paso 1: Diseñar la clase

```cpp
class Bureaucrat {
private:
    const std::string _name;    // No puede cambiar
    int _grade;                  // Puede cambiar (1-150)
};
```

**Importante**: 
- Grado 1 = MEJOR (mayor poder)
- Grado 150 = PEOR (menor poder)

### Paso 2: Crear excepciones personalizadas

Las excepciones deben heredar de `std::exception`:

```cpp
class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };
};
```

**Notas**:
- `throw()` → especifica que no lanza otras excepciones
- `const` → el método no modifica el objeto
- `what()` → retorna el mensaje de error

### Paso 3: Implementar constructor con validación

```cpp
Bureaucrat::Bureaucrat(const std::string& name, int grade) 
    : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();  // Menor número = grado más alto
    if (grade > 150)
        throw GradeTooLowException();   // Mayor número = grado más bajo
}
```

### Paso 4: Implementar métodos de incremento/decremento

```cpp
void Bureaucrat::incrementGrade() {
    // Incrementar = mejorar = bajar número
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;  // 3 → 2 (mejor)
}

void Bureaucrat::decrementGrade() {
    // Decrementar = empeorar = subir número
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;  // 75 → 76 (peor)
}
```

### Paso 5: Implementar operador <<

```cpp
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
```

**Uso:**
```cpp
Bureaucrat alice("Alice", 1);
std::cout << alice << std::endl;
// Output: Alice, bureaucrat grade 1.
```

---

## 📋 EJERCICIO 01 - Form

### Paso 1: Crear clase Form similar a Bureaucrat

```cpp
class Form {
private:
    const std::string _name;
    bool _isSigned;              // false por defecto
    const int _gradeToSign;      // Validar en constructor
    const int _gradeToExecute;   // Validar en constructor
};
```

### Paso 2: Implementar método beSigned()

```cpp
void Form::beSigned(const Bureaucrat& bureaucrat) {
    // Grado MENOR (número pequeño) = más poder = puede firmar
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}
```

**Ejemplo**:
- Form requiere grado 75
- Bureaucrat tiene grado 50
- 50 < 75 → Sí puede firmar ✅
- Bureaucrat tiene grado 100
- 100 > 75 → No puede firmar ❌

### Paso 3: Agregar signForm() a Bureaucrat

```cpp
void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
```

**Manejo elegante**:
- Intenta firmar
- Si falla, captura la excepción
- Imprime mensaje amigable

---

## 🔄 Conceptos Clave

### Forward Declaration

```cpp
// En Bureaucrat.hpp
class Form;  // Declarar que existe Form

class Bureaucrat {
public:
    void signForm(Form& form);  // Usar Form aquí
};

// En Bureaucrat.cpp
#include "Form.hpp"  // Incluir la definición completa
```

### Atributos const

```cpp
// En constructor
Form::Form(const std::string& name, int gradeToSign)
    : _name(name),           // const: se asigna aquí
      _gradeToSign(gradeToSign) // const: se asigna aquí
{
    // No puedes cambiar _name o _gradeToSign después
    // _name = "otro";  // ERROR!
}
```

### Orthodox Canonical Form

Toda clase debe tener:

```cpp
class MiClase {
private:
    // Versiones privadas para no usarlas
    MiClase();                              // Constructor por defecto
    MiClase(const MiClase& other);          // Constructor copia
    MiClase& operator=(const MiClase& other); // Asignación

public:
    MiClase(std::string name);              // Constructor parametrizado
    ~MiClase();                             // Destructor

    // Otros métodos...
};
```

---

## 🧪 Cómo Probar

### Compilación

```bash
cd /home/alcarden/Desktop/CPP/cpp05/ex00
make clean && make
./bureaucrat
```

### Verificar Excepciones

```cpp
try {
    Bureaucrat invalid("Test", 0);  // Grado inválido
}
catch (std::exception& e) {
    std::cout << "Caught: " << e.what() << std::endl;
}
```

### Verificar Output

```cpp
Bureaucrat b("Alice", 1);
std::cout << b << std::endl;
// Debe imprimir: Alice, bureaucrat grade 1.
```

---

## 🎯 Checklist Ejercicio 00

- [ ] Archivo `Bureaucrat.hpp` con include guards
- [ ] Archivo `Bureaucrat.cpp` con implementaciones
- [ ] Excepciones `GradeTooHighException` y `GradeTooLowException`
- [ ] Constructor que valida grado
- [ ] Getters: `getName()` y `getGrade()`
- [ ] Métodos: `incrementGrade()` y `decrementGrade()`
- [ ] Operador `<<` sobrecargado
- [ ] Archivo `main.cpp` con al menos 7 casos de prueba
- [ ] Archivo `Makefile` con compilación C++98
- [ ] Compila sin errores con `-Wall -Wextra -Werror`

## 🎯 Checklist Ejercicio 01

- [ ] Archivos anteriores funcionan
- [ ] Archivo `Form.hpp` con include guards
- [ ] Archivo `Form.cpp` con implementaciones
- [ ] Excepciones propias en Form
- [ ] Constructor valida grados
- [ ] Getters para todos los atributos
- [ ] Método `beSigned(const Bureaucrat&)`
- [ ] Método `signForm(Form&)` en Bureaucrat
- [ ] Operador `<<` sobrecargado para Form
- [ ] Manejo de excepciones con try/catch
- [ ] main.cpp con casos de éxito y fracaso
- [ ] Compila sin errores

---

## 💡 Errores Comunes

### ❌ Error: No incluir cabeceras

```cpp
// Incorrecto
std::cout << e.what();  // ¿Qué es what()?

// Correcto
#include <exception>
#include <iostream>
```

### ❌ Error: Olvidar throw()

```cpp
// Incorrecto
const char* what() const { return "error"; }

// Correcto
const char* what() const throw() { return "error"; }
```

### ❌ Error: Atributo no const

```cpp
// Incorrecto: puede cambiar después
Form(std::string name) : _name(name) {}

// Correcto: asegurar que no cambie
Form(std::string name) : _name(name) {}
// _name es const en la clase
```

### ❌ Error: Lógica de grados invertida

```cpp
// Incorrecto: grado 1 debería ser mejor
if (_grade > 1) throw exception;

// Correcto: grado 1 es el MEJOR
if (_grade < 1) throw exception;
```

---

## 🚀 Ejercicio 02 Preview

En ejercicio 02, convertiremos Form en AForm (clase abstracta):

```cpp
class AForm {
public:
    virtual void execute(const Bureaucrat& executor) const = 0;
    // = 0 significa que es "método puro" (abstract)
};

class ShrubberyCreationForm : public AForm {
public:
    virtual void execute(const Bureaucrat& executor) const {
        // Crear archivo con árboles
    }
};
```

---

## 📚 Referencias Útiles

- **std::exception**: Clase base de excepciones
- **throw**: Lanza una excepción
- **try/catch**: Captura excepciones
- **const**: Atributos inmutables
- **virtual**: Métodos que se pueden sobrescribir
- **= 0**: Indica método puro (clase abstracta)

---

**¡Ahora estás listo para empezar! ¡A programar! 💻**
