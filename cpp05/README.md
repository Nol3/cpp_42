# 📚 C++ Module 05 - Hoja de Ruta y Progreso

## ✅ Completado

### Ejercicio 00: Bureaucrat ✅
**Objetivo**: Introducir excepciones personalizadas en C++

**Lo que implementamos:**
- Clase `Bureaucrat` con:
  - Atributo `_name` (const)
  - Atributo `_grade` (1-150)
  - Constructor que valida el grado
  - Dos excepciones personalizadas: `GradeTooHighException` y `GradeTooLowException`
  - Métodos: `getName()`, `getGrade()`, `incrementGrade()`, `decrementGrade()`
  - Sobrecarga del operador `<<` para impresión
  
**Conceptos clave:**
- Las excepciones heredan de `std::exception`
- Método `what()` retorna un mensaje descriptivo
- El grado 1 es el MEJOR (mayor poder)
- incrementGrade() reduce el número (1 → 0 arroja excepción)
- decrementGrade() aumenta el número (150 → 151 arroja excepción)

**Estado**: ✅ Compilado y probado exitosamente

---

### Ejercicio 01: Form ✅
**Objetivo**: Trabajar con relaciones entre clases y excepciones

**Lo que implementamos:**
- Clase `Form` con:
  - Atributo `_name` (const)
  - Atributo `_isSigned` (boolean)
  - Atributo `_gradeToSign` (const, 1-150)
  - Atributo `_gradeToExecute` (const, 1-150)
  - Excepciones propias: `GradeTooHighException` y `GradeTooLowException`
  - Getters para todos los atributos
  - Método `beSigned(const Bureaucrat& bureaucrat)` que valida el grado
  - Sobrecarga del operador `<<` para impresión

- Extensión de `Bureaucrat`:
  - Método `signForm(Form& form)` que intenta firmar un formulario
  - Manejo de excepciones con try/catch
  - Impresión de éxito o fallo

**Conceptos clave:**
- Parámetro forward declaration (class Form; / class Bureaucrat;)
- Captura de excepciones y manejo elegante
- Validación: bureaucrat.grade <= form.gradeToSign para firmar

**Estado**: ✅ Compilado y probado exitosamente

---

## 📋 Próximos Pasos

### Ejercicio 02: AForm (Clases Abstractas) ⏳
**Objetivo**: Introducir polimorfismo y clases abstractas

**Lo que necesitas hacer:**
1. Convertir `Form` en clase abstracta `AForm`
2. Crear método virtual puro: `virtual void execute(const Bureaucrat& executor) const = 0`
3. Crear 3 subclases concretas:

   **ShrubberyCreationForm** (signo: 145, exec: 137)
   - Crea un archivo `<target>_shrubbery`
   - Escribe árboles ASCII dentro
   
   **RobotomyRequestForm** (signo: 72, exec: 45)
   - Imprime sonidos de perforación
   - 50% de éxito: "<target> has been robotomized"
   - 50% de fracaso: "robotomy failed"
   
   **PresidentialPardonForm** (signo: 25, exec: 5)
   - Imprime: "<target> has been pardoned by Zaphod Beeblebrox"

4. Método `executeForm(AForm const & form) const` en Bureaucrat
5. Validaciones: forma firmada + grado suficiente para ejecutar

---

### Ejercicio 03: Intern (Factory Pattern) ⏳
**Objetivo**: Implementar patrón Factory de forma elegante

**Lo que necesitas hacer:**
1. Crear clase `Intern` (sin nombre, sin grado, sin características)
2. Método `AForm* makeForm(const std::string& formName, const std::string& target)`
3. Retorna puntero a forma correspondiente
4. Imprime: "Intern creates <formName>"
5. **IMPORTANTE**: Evitar if/else excesivos (usar array de punteros a funciones o similar)

---

## 🎯 Conceptos Importantes

1. **Excepciones Personalizadas**: Heredan de `std::exception`, implementan `what()`
2. **Orthodox Canonical Form**: Constructor por defecto, copiar, asignación, destructor
3. **Clases Abstractas**: Contienen métodos virtuales puros
4. **Polimorfismo**: Uso de referencias/punteros a clase base
5. **Factory Pattern**: Crear objetos sin especificar clases concretas
6. **Forward Declarations**: Evitar inclusiones circulares

---

## 📂 Estructura de Directorios

```
cpp05/
├── ex00/
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── Form.hpp
│   ├── Form.cpp
│   ├── main.cpp
│   └── Makefile
├── ex02/
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── AForm.hpp
│   ├── AForm.cpp
│   ├── ShrubberyCreationForm.hpp
│   ├── ShrubberyCreationForm.cpp
│   ├── RobotomyRequestForm.hpp
│   ├── RobotomyRequestForm.cpp
│   ├── PresidentialPardonForm.hpp
│   ├── PresidentialPardonForm.cpp
│   ├── main.cpp
│   └── Makefile
└── ex03/
    ├── [Archivos anteriores]
    ├── Intern.hpp
    ├── Intern.cpp
    ├── main.cpp
    └── Makefile
```

---

## 🧪 Compilación

```bash
# Compilar
c++ -Wall -Wextra -Werror -std=c++98 -c ClassName.cpp
c++ -Wall -Wextra -Werror -std=c++98 -o program main.o Classname.o

# O usar Makefile
make clean && make
```

---

**Creado**: 16 de Noviembre, 2025
