# 📑 ÍNDICE - C++ MODULE 05

## 📖 Documentos Disponibles

### 1️⃣ **INICIO_RAPIDO.txt** ⭐ EMPIEZA AQUÍ
- **Tamaño**: 7.7 KB
- **Tiempo de lectura**: 5 minutos
- **Contenido**:
  - ✅ Qué se ha completado
  - 📁 Estructura de carpetas
  - 🎯 Conceptos clave aprendidos
  - 🚀 Cómo usar lo creado
  - 💡 Puntos importantes para recordar
  - 📚 Archivos de referencia
  - ❓ Preguntas frecuentes
  - 🎓 Próximos ejercicios
  - ✨ Resumen final

### 2️⃣ **EXPLICACION.md** 📚 TUTORIAL DETALLADO
- **Tamaño**: 7.7 KB
- **Tiempo de lectura**: 20 minutos
- **Contenido**:
  - 📖 Introducción a excepciones
  - 🏗️ Explicación paso a paso del ejercicio 00
  - 📋 Explicación paso a paso del ejercicio 01
  - 🔄 Conceptos clave (forward declarations, atributos const, etc)
  - 🧪 Cómo probar el código
  - 🎯 Checklist de cada ejercicio
  - 💡 Errores comunes
  - 🚀 Preview del ejercicio 02
  - 📚 Referencias útiles

### 3️⃣ **README.md** 🗺️ HOJA DE RUTA
- **Tamaño**: 4.8 KB
- **Tiempo de lectura**: 10 minutos
- **Contenido**:
  - 📋 Resumen de todos los ejercicios
  - ✅ Estado de completación
  - 📂 Estructura de directorios
  - 🧪 Conceptos importantes
  - 🎯 Próximos pasos
  - 🧪 Compilación y pruebas

### 4️⃣ **PROGRESS.md** 📊 ESTADO DEL PROYECTO
- **Tamaño**: 14.8 KB
- **Tiempo de lectura**: 15 minutos
- **Contenido**:
  - 📋 Detalles de ejercicio 00 (✅ completado)
  - 📋 Detalles de ejercicio 01 (✅ completado)
  - 📋 Detalles de ejercicio 02 (⏳ pendiente)
  - 📋 Detalles de ejercicio 03 (⏳ pendiente)
  - 📊 Barra de progreso visual
  - 🚀 Próximos pasos
  - 💡 Tips importantes

### 5️⃣ **COMANDOS_UTILES.sh** ⚙️ UTILIDADES
- **Tamaño**: 8.4 KB
- **Contenido**:
  - 🔧 Comandos de compilación
  - 🧪 Comandos de ejecución
  - 📂 Comandos de navegación
  - 📖 Comandos para leer código
  - 🧹 Comandos de limpieza
  - ✅ Comandos de verificación
  - 📊 Comandos de estadísticas
  - 💾 Comandos de Git
  - ✨ Aliases rápidos para ~/.zshrc

---

## 🗂️ Estructura de Archivos

```
cpp05/
├── 📄 INICIO_RAPIDO.txt          ← Empieza aquí
├── 📄 EXPLICACION.md             ← Tutorial paso a paso
├── 📄 README.md                  ← Hoja de ruta
├── 📄 PROGRESS.md                ← Estado del proyecto
├── 📄 COMANDOS_UTILES.sh         ← Comandos útiles
│
├── ex00/ (✅ COMPLETADO)
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── main.cpp
│   └── Makefile
│
├── ex01/ (✅ COMPLETADO)
│   ├── Bureaucrat.hpp
│   ├── Bureaucrat.cpp
│   ├── Form.hpp
│   ├── Form.cpp
│   ├── main.cpp
│   └── Makefile
│
├── ex02/ (⏳ PENDIENTE)
└── ex03/ (⏳ PENDIENTE)
```

---

## 🎯 Cómo Usar Este Proyecto

### 1. Primera Lectura (5 minutos)
```
1. Abre: INICIO_RAPIDO.txt
2. Lee la sección "¿QUÉ SE HA COMPLETADO?"
3. Revisa la estructura creada
```

### 2. Entender el Código (20 minutos)
```
1. Abre: EXPLICACION.md
2. Lee la sección "EJERCICIO 00 - Bureaucrat"
3. Abre: /home/alcarden/Desktop/CPP/cpp05/ex00/Bureaucrat.hpp
4. Abre: /home/alcarden/Desktop/CPP/cpp05/ex00/Bureaucrat.cpp
5. Compara con la explicación
```

### 3. Compilar y Ejecutar (5 minutos)
```bash
cd /home/alcarden/Desktop/CPP/cpp05/ex00
make clean && make
./bureaucrat
```

### 4. Estudiar Form (20 minutos)
```
1. Abre: EXPLICACION.md
2. Lee la sección "EJERCICIO 01 - Form"
3. Abre: /home/alcarden/Desktop/CPP/cpp05/ex01/Form.hpp
4. Abre: /home/alcarden/Desktop/CPP/cpp05/ex01/Form.cpp
5. Compara con la explicación
```

### 5. Compilar ex01 (5 minutos)
```bash
cd /home/alcarden/Desktop/CPP/cpp05/ex01
make clean && make
./form
```

### 6. Planificar ex02 (10 minutos)
```
1. Abre: PROGRESS.md
2. Lee la sección "EJERCICIO 02"
3. Comprende qué es una clase abstracta
```

---

## 💡 Recomendaciones

### Para Aprender C++
1. Lee **EXPLICACION.md** primero
2. Luego lee el código en el editor
3. Intenta modificar el código
4. Compila y observa los cambios

### Para Próximos Ejercicios
1. Consulta **PROGRESS.md** para detalles
2. Usa **COMANDOS_UTILES.sh** para compilar rápido
3. Refiere al **README.md** para conceptos

### Para Debugging
1. Lee los mensajes de error completos
2. Busca en **EXPLICACION.md** la solución
3. Verifica que uses `make clean && make`

---

## 🚀 Comandos Rápidos

```bash
# Ir a cpp05
cd /home/alcarden/Desktop/CPP/cpp05

# Compilar ex00
cd ex00 && make clean && make && ./bureaucrat

# Compilar ex01
cd ../ex01 && make clean && make && ./form

# Limpiar todo
make fclean

# Ver estructura
ls -la
```

---

## 📊 Estadísticas

| Métrica | Valor |
|---------|-------|
| Ejercicios completados | 2/4 (50%) |
| Líneas de código | ~300 |
| Archivos creados | 13 |
| Líneas de documentación | 400+ |
| Casos de prueba | 13 |
| KB de documentación | 38.7 |

---

## ✅ Requisitos Cumplidos

- [x] Excepciones personalizadas
- [x] Atributos const
- [x] Validación en constructor
- [x] Métodos get/set
- [x] Operador << sobrecargado
- [x] Manejo de excepciones con try/catch
- [x] Forward declarations
- [x] Include guards
- [x] Orthodox Canonical Form
- [x] Compilación sin warnings
- [x] Pruebas exhaustivas
- [x] Documentación completa

---

## 📝 Notas Importantes

### Grado vs Poder
- **Grado 1** = MEJOR (máximo poder)
- **Grado 150** = PEOR (mínimo poder)
- Grado menor = más autoridad

### Compilación
- Siempre: `c++ -Wall -Wextra -Werror -std=c++98`
- No STL en módulo 05
- No printf/malloc/free

### Excepciones
- Heredan de `std::exception`
- Implementan `what() const throw()`
- Se lanzan con `throw`
- Se capturan con `catch`

---

## 🎓 Próximos Pasos

### Ejercicio 02
1. Clase abstracta AForm
2. Tres subclases concretas
3. Método virtual execute()

### Ejercicio 03
1. Clase Intern
2. Factory Pattern
3. Método makeForm()

---

## 📞 Contacto / Dudas

Si tienes dudas:
1. Revisa **EXPLICACION.md**
2. Consulta **PROGRESS.md**
3. Verifica los ejemplos en los archivos .cpp
4. Lee los comentarios en el código

---

**Última actualización**: 16 de Noviembre, 2025  
**Versión**: 1.0  
**Proyecto**: cpp_42  
**Estado**: 50% Completado ✅
