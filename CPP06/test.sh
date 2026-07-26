#!/bin/bash

# Colores para la salida
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # Sin color

PROGRAM="./ScalarConverter"

# Verificar que el programa existe
if [ ! -f "$PROGRAM" ]; then
    echo -e "${RED}Error: $PROGRAM no encontrado. Compila primero.${NC}"
    exit 1
fi

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   TESTS AUTOMATIZADOS - CPP06/ex00   ${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""

# Función para ejecutar un test
run_test() {
    local input="$1"
    local description="$2"
    
    echo -e "${YELLOW}▶ Test: ${description}${NC}"
    echo -e "${YELLOW}  Input: ${input}${NC}"
    echo -e "${BLUE}  Output:${NC}"
    $PROGRAM "$input"
    echo ""
}

# ============================================
# 1. TESTS BÁSICOS
# ============================================
echo -e "${GREEN}=== 1. TESTS BÁSICOS ===${NC}"
echo ""

run_test "0" "Int: cero"
run_test "42" "Int: positivo"
run_test "-42" "Int: negativo"
run_test "2147483647" "Int: INT_MAX"
run_test "-2147483648" "Int: INT_MIN"

# ============================================
# 2. TESTS DE CHAR
# ============================================
echo -e "${GREEN}=== 2. TESTS DE CHAR ===${NC}"
echo ""

run_test "'a'" "Char: letra minúscula"
run_test "'Z'" "Char: letra mayúscula"
run_test "'5'" "Char: dígito"
run_test "' '" "Char: espacio"
run_test "'@'" "Char: símbolo"
run_test "'\\'" "Char: barra invertida"

# ============================================
# 3. TESTS DE FLOAT
# ============================================
echo -e "${GREEN}=== 3. TESTS DE FLOAT ===${NC}"
echo ""

run_test "0.0f" "Float: cero"
run_test "42.0f" "Float: positivo"
run_test "-42.0f" "Float: negativo"
run_test "42.42f" "Float: con decimales"
run_test "123456f" "Float: sin punto decimal"
run_test "123456.789f" "Float: con decimales"
run_test "123456789101112f" "Float: overflow de int"
run_test "123456789101112235634353242332355f" "Float: overflow de float"

# ============================================
# 4. TESTS DE DOUBLE
# ============================================
echo -e "${GREEN}=== 4. TESTS DE DOUBLE ===${NC}"
echo ""

run_test "0.0" "Double: cero"
run_test "42.0" "Double: positivo"
run_test "-42.0" "Double: negativo"
run_test "42.42" "Double: con decimales"
run_test "123456789101112.0" "Double: grande"
run_test "123456789101112235634353242332355.0" "Double: overflow de float"

# ============================================
# 5. PSEUDO-LITERALES (nan, inf)
# ============================================
echo -e "${GREEN}=== 5. PSEUDO-LITERALES ===${NC}"
echo ""

run_test "nan" "NaN"
run_test "nanf" "NaN float"
run_test "inf" "+inf"
run_test "inff" "+inf float"
run_test "+inf" "+inf"
run_test "-inf" "-inf"
run_test "+inff" "+inf float"
run_test "-inff" "-inf float"

# ============================================
# 6. CASOS INVÁLIDOS
# ============================================
echo -e "${GREEN}=== 6. CASOS INVÁLIDOS ===${NC}"
echo ""

run_test "a" "Char sin comillas"
run_test "@" "Símbolo sin comillas"
run_test "123.456.789" "Doble punto"
run_test "123f" "Float sin punto"
run_test "123.f" "Punto sin dígitos después"
run_test "123.45.67f" "Doble punto en float"
run_test "---123" "Múltiples signos"
run_test "123abc" "Letras después del número"

# ============================================
# 7. VALORES LÍMITE
# ============================================
echo -e "${GREEN}=== 7. VALORES LÍMITE ===${NC}"
echo ""

run_test "2147483648" "Int: INT_MAX + 1"
run_test "-2147483649" "Int: INT_MIN - 1"
run_test "999999999999999999" "Int: muy grande"
run_test "-999999999999999999" "Int: muy negativo"

# ============================================
# 8. CASOS MIXTOS
# ============================================
echo -e "${GREEN}=== 8. CASOS MIXTOS ===${NC}"
echo ""

run_test "0.0" "Double: cero"
run_test "0f" "Float: cero sin punto"
run_test "0.0f" "Float: cero con punto"
run_test "37." "Double: punto al final"
run_test "42.0" "Double: con decimales"

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}   FIN DE LOS TESTS${NC}"
echo -e "${GREEN}========================================${NC}"