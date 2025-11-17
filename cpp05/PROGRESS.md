╔═══════════════════════════════════════════════════════════════════════╗
║           C++ MODULE 05 - REPETITION AND EXCEPTIONS                 ║
║                   HOJA DE RUTA - ESTADO DEL PROYECTO                ║
╚═══════════════════════════════════════════════════════════════════════╝

┌─────────────────────────────────────────────────────────────────────┐
│ EJERCICIO 00: "Mommy, when I grow up, I want to be a bureaucrat!"   │
│ STATUS: ✅ COMPLETADO                                               │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│ 📋 Conceptos Aprendidos:                                            │
│  • Excepciones personalizadas heredando de std::exception          │
│  • Método what() que retorna mensajes de error                    │
│  • Validación de grados en constructor y métodos                 │
│  • Sobrecarga del operador << (inserción)                         │
│  • Orthodox Canonical Form                                        │
│                                                                     │
│ 📁 Archivos Creados:                                               │
│  ✓ Bureaucrat.hpp      - Interfaz de la clase                    │
│  ✓ Bureaucrat.cpp      - Implementación                           │
│  ✓ main.cpp            - Pruebas exhaustivas                      │
│  ✓ Makefile            - Compilación automática                   │
│                                                                     │
│ 🎯 Requisitos Implementados:                                        │
│  ✓ Atributo nombre (const)                                        │
│  ✓ Atributo grado (1-150)                                         │
│  ✓ Excepciones: GradeTooHighException, GradeTooLowException     │
│  ✓ Getters: getName(), getGrade()                                │
│  ✓ Métodos: incrementGrade(), decrementGrade()                   │
│  ✓ Operador << para impresión                                    │
│                                                                     │
│ 🧪 Pruebas Ejecutadas: ✅ 7/7 casos de prueba pasados             │
│  • Creación de bureaucrats válidos                                │
│  • Incremento de grado                                            │
│  • Decremento de grado                                            │
│  • Excepción al incrementar grade 1                               │
│  • Excepción al crear grade 0                                     │
│  • Excepción al crear grade 151                                   │
│  • Excepción al decrementar grade 150                             │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────┐
│ EJERCICIO 01: "Form up, maggots!"                                   │
│ STATUS: ✅ COMPLETADO                                               │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│ 📋 Conceptos Aprendidos:                                            │
│  • Relación entre clases (Bureaucrat ↔ Form)                      │
│  • Forward declarations para evitar inclusiones circulares       │
│  • Parámetros const reference (const Bureaucrat&)                │
│  • Manejo de excepciones con try/catch                           │
│  • Atributos const en clase (const en init list)                 │
│                                                                     │
│ 📁 Archivos Creados:                                               │
│  ✓ Bureaucrat.hpp      - Versión mejorada con signForm()         │
│  ✓ Bureaucrat.cpp      - Con manejo de excepciones               │
│  ✓ Form.hpp            - Interfaz de formularios                 │
│  ✓ Form.cpp            - Implementación de formularios           │
│  ✓ main.cpp            - Casos de prueba avanzados               │
│  ✓ Makefile            - Compilación de 3 archivos .cpp         │
│                                                                     │
│ 🎯 Requisitos Implementados:                                        │
│  ✓ Form con atributos: nombre, isSigned, gradeToSign,           │
│    gradeToExecute (todos const excepto isSigned)                 │
│  ✓ Excepciones propias: Form::GradeTooHighException,             │
│    Form::GradeTooLowException                                    │
│  ✓ Getters para todos los atributos                              │
│  ✓ Método beSigned(const Bureaucrat&)                            │
│  ✓ Método signForm(Form&) en Bureaucrat                          │
│  ✓ Manejo elegante de excepciones                                │
│  ✓ Operador << para impresión de formularios                     │
│                                                                     │
│ 🧪 Pruebas Ejecutadas: ✅ 6/6 casos de prueba pasados             │
│  • Creación de formularios y bureaucrats                          │
│  • Alice (grade 1) firmando Form A (requires 1)                  │
│  • Charlie (grade 50) firmando Form B (requires 75)              │
│  • Bob (grade 150) NO puede firmar Form B (requires 75)          │
│  • Alice (grade 1) firmando Form C (requires 150)                │
│  • Excepciones en creación de formularios inválidos              │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────┐
│ EJERCICIO 02: "No, you need form 28B, not 28C..."                   │
│ STATUS: ⏳ PENDIENTE                                                │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│ 📋 Conceptos a Aprender:                                            │
│  • Clases abstractas (virtual puro = 0)                           │
│  • Polimorfismo mediante herencia                                 │
│  • Métodos virtuales override                                    │
│  • Punteros a clase base para objetos derivados                 │
│                                                                     │
│ 📁 Archivos a Crear:                                               │
│  ☐ AForm.hpp / AForm.cpp       - Clase abstracta base           │
│  ☐ ShrubberyCreationForm.hpp/cpp - Crea archivo con árboles    │
│  ☐ RobotomyRequestForm.hpp/cpp   - Simula robotomía (50/50)    │
│  ☐ PresidentialPardonForm.hpp/cpp - Emite perdón              │
│  ☐ main.cpp                   - Casos de prueba                │
│  ☐ Makefile                   - Compilación                    │
│                                                                     │
│ 🎯 Requisitos a Implementar:                                        │
│  • Convertir Form en AForm (clase abstracta)                     │
│  • Método virtual puro execute(Bureaucrat const&)               │
│  • 3 clases concretas con execute() implementado                │
│  • ShrubberyCreationForm: signos 145/137, crea archivo          │
│  • RobotomyRequestForm: signos 72/45, 50% éxito                 │
│  • PresidentialPardonForm: signos 25/5, emite perdón            │
│  • executeForm() en Bureaucrat                                   │
│  • Validaciones: forma firmada + grado suficiente               │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────┐
│ EJERCICIO 03: "At least this beats coffee-making"                   │
│ STATUS: ⏳ PENDIENTE                                                │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│ 📋 Conceptos a Aprender:                                            │
│  • Factory Pattern                                               │
│  • Punteros a funciones / Array de funciones                    │
│  • Alternativas a if/else excesivos                             │
│  • Creación dinámica de objetos (new)                           │
│                                                                     │
│ 📁 Archivos a Crear:                                               │
│  ☐ Intern.hpp / Intern.cpp - Clase factory                    │
│  ☐ main.cpp              - Casos de prueba                     │
│  ☐ Makefile              - Compilación                         │
│                                                                     │
│ 🎯 Requisitos a Implementar:                                        │
│  • Clase Intern (sin nombre, sin grado, sin características)    │
│  • Método makeForm(string, string) → AForm*                    │
│  • Retorna puntero a formulario correspondiente                 │
│  • Imprime "Intern creates <formName>"                         │
│  • SIN if/else excesivos (muy importante para evaluación)       │
│  • Manejo de nombres de formas inválidos                        │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘

═══════════════════════════════════════════════════════════════════════

📊 PROGRESO GENERAL
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

[████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░] 50%

Ejercicio 00: ████████████████████████ 100% ✅
Ejercicio 01: ████████████████████████ 100% ✅
Ejercicio 02: ░░░░░░░░░░░░░░░░░░░░░░░░░ 0%   ⏳
Ejercicio 03: ░░░░░░░░░░░░░░░░░░░░░░░░░ 0%   ⏳

═══════════════════════════════════════════════════════════════════════

🚀 PRÓXIMOS PASOS

1. Leer atentamente la especificación del ejercicio 02
2. Entender qué es una clase abstracta y método virtual puro
3. Implementar AForm heredando de la estructura actual de Form
4. Crear las 3 subclases concretas
5. Probar exhaustivamente
6. Pasar a ejercicio 03 con pattern factory elegante

═══════════════════════════════════════════════════════════════════════

💡 TIPS IMPORTANTES

• Guardar este documento como referencia
• Comprobar compilación con: make clean && make
• Usar try/catch para pruebas de excepciones
• C++98 es estricto: verificar sintaxis
• Evitar STL (vector, map) - no se permite en módulo 05
• Evitar printf/malloc/free - usar iostream y new/delete
• Todos los destructores deben ser virtuales en clases base

═══════════════════════════════════════════════════════════════════════
Proyecto: cpp_42 | Branch: main | Fecha: 16 Nov 2025
═══════════════════════════════════════════════════════════════════════
