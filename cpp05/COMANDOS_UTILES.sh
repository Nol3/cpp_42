#!/bin/bash

# ═══════════════════════════════════════════════════════════════════════════
# C++ MODULE 05 - COMANDOS ÚTILES
# ═══════════════════════════════════════════════════════════════════════════

echo "📋 COMANDOS ÚTILES PARA C++ MODULE 05"
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "🔧 COMPILACIÓN"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Compilar ex00 (Bureaucrat):"
echo "   cd /home/alcarden/Desktop/CPP/cpp05/ex00 && make clean && make"
echo ""

echo "2️⃣  Compilar ex01 (Form):"
echo "   cd /home/alcarden/Desktop/CPP/cpp05/ex01 && make clean && make"
echo ""

echo "3️⃣  Compilar todos (bash loop):"
echo "   for i in 0 1; do cd ex0\$i && make clean && make && cd ..; done"
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "🧪 EJECUCIÓN"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Ejecutar ex00:"
echo "   cd /home/alcarden/Desktop/CPP/cpp05/ex00 && ./bureaucrat"
echo ""

echo "2️⃣  Ejecutar ex01:"
echo "   cd /home/alcarden/Desktop/CPP/cpp05/ex01 && ./form"
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "📂 NAVEGACIÓN"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Ir a cpp05:"
echo "   cd /home/alcarden/Desktop/CPP/cpp05"
echo ""

echo "2️⃣  Listar estructura:"
echo "   tree /home/alcarden/Desktop/CPP/cpp05"
echo "   (o: find . -type f -name '*.cpp' -o -name '*.hpp' | sort)"
echo ""

echo "3️⃣  Ver todos los archivos:"
echo "   ls -la /home/alcarden/Desktop/CPP/cpp05/ex0*"
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "📖 LEER CÓDIGO"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Ver Bureaucrat.hpp de ex00:"
echo "   cat /home/alcarden/Desktop/CPP/cpp05/ex00/Bureaucrat.hpp"
echo ""

echo "2️⃣  Ver Form.cpp de ex01:"
echo "   cat /home/alcarden/Desktop/CPP/cpp05/ex01/Form.cpp"
echo ""

echo "3️⃣  Ver main.cpp de ex01 (casos de prueba):"
echo "   cat /home/alcarden/Desktop/CPP/cpp05/ex01/main.cpp"
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "🧹 LIMPIEZA"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Limpiar ex00:"
echo "   cd /home/alcarden/Desktop/CPP/cpp05/ex00 && make fclean"
echo ""

echo "2️⃣  Limpiar todos:"
echo "   cd /home/alcarden/Desktop/CPP/cpp05 && for i in 0 1; do cd ex0\$i && make fclean && cd ..; done"
echo ""

echo "3️⃣  Eliminar todos los .o y ejecutables:"
echo "   find /home/alcarden/Desktop/CPP/cpp05 -name '*.o' -delete"
echo "   find /home/alcarden/Desktop/CPP/cpp05 -type f ! -name '*.cpp' ! -name '*.hpp' ! -name 'Makefile' -delete"
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "✅ VERIFICACIÓN"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Verificar que compila sin errores:"
echo "   cd /home/alcarden/Desktop/CPP/cpp05/ex00 && c++ -Wall -Wextra -Werror -std=c++98 -c Bureaucrat.cpp"
echo ""

echo "2️⃣  Buscar includes circulares:"
echo "   grep -r '#include' /home/alcarden/Desktop/CPP/cpp05/ex01"
echo ""

echo "3️⃣  Buscar uso de STL prohibido:"
echo "   grep -r '#include <vector\\|#include <map\\|#include <list' /home/alcarden/Desktop/CPP/cpp05"
echo ""

echo "4️⃣  Buscar printf/malloc/free prohibidos:"
echo "   grep -r 'printf\\|malloc\\|free' /home/alcarden/Desktop/CPP/cpp05"
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "📊 ESTADÍSTICAS"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Contar líneas de código:"
echo "   wc -l /home/alcarden/Desktop/CPP/cpp05/ex00/*.cpp /home/alcarden/Desktop/CPP/cpp05/ex00/*.hpp"
echo ""

echo "2️⃣  Listar todos los métodos:"
echo "   grep -r 'void\\|int\\|bool' /home/alcarden/Desktop/CPP/cpp05/ex00/*.hpp | grep '('  "
echo ""

# ─────────────────────────────────────────────────────────────────────────
echo "💾 GIT"
echo "─────────────────────────────────────────────────────────────────────"

echo ""
echo "1️⃣  Ver cambios:"
echo "   cd /home/alcarden/Desktop/CPP && git status"
echo ""

echo "2️⃣  Agregar cambios:"
echo "   cd /home/alcarden/Desktop/CPP && git add cpp05/"
echo ""

echo "3️⃣  Hacer commit:"
echo "   cd /home/alcarden/Desktop/CPP && git commit -m 'feat: cpp05 ex00 and ex01 completed'"
echo ""

# ─────────────────────────────════════════════════════════════════════════════
echo ""
echo "═══════════════════════════════════════════════════════════════════════════"
echo "✨ ALIASES RÁPIDOS (copiar en ~/.zshrc)"
echo "═══════════════════════════════════════════════════════════════════════════"
echo ""
echo "alias cpp5='cd /home/alcarden/Desktop/CPP/cpp05'"
echo "alias cpp5ex0='cd /home/alcarden/Desktop/CPP/cpp05/ex00'"
echo "alias cpp5ex1='cd /home/alcarden/Desktop/CPP/cpp05/ex01'"
echo "alias makeex0='cd /home/alcarden/Desktop/CPP/cpp05/ex00 && make clean && make'"
echo "alias makeex1='cd /home/alcarden/Desktop/CPP/cpp05/ex01 && make clean && make'"
echo ""

