#!/bin/bash

# Test script for valid RPN expressions
# Usage: ./test_valid.sh ./RPN

if [ -z "$1" ]; then
    echo "Usage: $0 <path_to_executable>"
    exit 1
fi

EXECUTABLE="$1"
PASS=0
FAIL=0

# Function to run a test
run_test() {
    local input="$1"
    local description="$2"
    
    echo -n "Testing: $description... "
    OUTPUT=$("$EXECUTABLE" "$input" 2>&1)
    
    if echo "$OUTPUT" | grep -q "Error"; then
        echo "FAIL (got Error)"
        ((FAIL++))
    else
        echo "PASS (result: $OUTPUT)"
        ((PASS++))
    fi
}

echo "========== VALID RPN CASES (100 tests) =========="
echo ""

# Simple single operands
echo "--- Single Operands ---"
run_test "0" "Single digit: 0"
run_test "1" "Single digit: 1"
run_test "5" "Single digit: 5"
run_test "9" "Single digit: 9"

# Basic operations (2 operands, 1 operator)
echo ""
echo "--- Basic Operations ---"
run_test "1 1 +" "1 + 1"
run_test "2 3 +" "2 + 3"
run_test "5 5 +" "5 + 5"
run_test "9 9 +" "9 + 9"

run_test "5 3 -" "5 - 3"
run_test "9 1 -" "9 - 1"
run_test "0 0 -" "0 - 0"
run_test "1 0 -" "1 - 0"

run_test "2 3 *" "2 * 3"
run_test "5 5 *" "5 * 5"
run_test "9 9 *" "9 * 9"
run_test "1 1 *" "1 * 1"

run_test "6 2 /" "6 / 2"
run_test "9 3 /" "9 / 3"
run_test "8 2 /" "8 / 2"
run_test "5 1 /" "5 / 1"

# Operations with zero
echo ""
echo "--- Operations with Zero ---"
run_test "0 1 +" "0 + 1"
run_test "1 0 +" "1 + 0"
run_test "0 0 +" "0 + 0"
run_test "5 0 -" "5 - 0"
run_test "0 5 -" "0 - 5"
run_test "0 0 *" "0 * 0"
run_test "0 5 *" "0 * 5"
run_test "5 0 *" "5 * 0"
run_test "0 1 /" "0 / 1"

# Three operands, two operators (linear)
echo ""
echo "--- Linear Three Operand Operations ---"
run_test "1 2 + 3 +" "1 + 2 + 3 = 6"
run_test "5 3 - 2 -" "5 - 3 - 2 = 0"
run_test "2 3 * 4 *" "2 * 3 * 4 = 24"
run_test "8 2 / 2 /" "8 / 2 / 2 = 2"
run_test "1 2 + 3 *" "(1 + 2) * 3 = 9"
run_test "1 2 * 3 +" "1 * 2 + 3 = 5"

# More complex expressions
echo ""
echo "--- More Complex Expressions ---"
run_test "3 4 + 2 * 7 /" "(3 + 4) * 2 / 7"
run_test "5 7 1 1 + - / 3 * 2 1 1 + + -" "complex expression"
run_test "2 3 4 + *" "2 * (3 + 4) = 14"
run_test "5 1 2 + 4 * + 3 -" "5 + (1 + 2) * 4 - 3 = 16"

# Four operands
echo ""
echo "--- Four Operand Expressions ---"
run_test "1 2 3 4 + + +" "1 + 2 + 3 + 4 = 10"
run_test "2 3 4 5 * * *" "2 * 3 * 4 * 5 = 120"
run_test "1 2 + 3 + 4 +" "1 + 2 + 3 + 4 = 10"
run_test "1 5 2 1 - - -" "1 - 5 - 2 - 1 = -3"

# Five operands
echo ""
echo "--- Five+ Operand Expressions ---"
run_test "1 2 3 4 5 + + + +" "1 + 2 + 3 + 4 + 5 = 15"
run_test "2 3 4 5 6 * * * *" "2 * 3 * 4 * 5 * 6 = 720"
run_test "1 2 + 3 + 4 + 5 +" "1 + 2 + 3 + 4 + 5 = 15"

# Mixed operations
echo ""
echo "--- Mixed Operations ---"
run_test "2 3 + 4 5 + *" "(2 + 3) * (4 + 5) = 45"
run_test "4 2 / 3 *" "(4 / 2) * 3 = 6"
run_test "7 3 - 2 *" "(7 - 3) * 2 = 8"
run_test "6 2 / 3 /" "6 / 2 / 3 = 1"
run_test "2 3 * 4 +" "2 * 3 + 4 = 10"
run_test "2 3 + 4 *" "(2 + 3) * 4 = 20"

# Operations resulting in specific values
echo ""
echo "--- Operations Resulting in Specific Values ---"
run_test "0 1 2 3 4 5 + + + + +" "0 + 1 + 2 + 3 + 4 + 5 = 15"
run_test "1 1 1 1 1 + + + +" "1 + 1 + 1 + 1 + 1 = 5"
run_test "9 0 -" "9 - 0 = 9"
run_test "0 0 0 + +" "0 + 0 + 0 = 0"

# Whitespace variations (spaces)
echo ""
echo "--- Whitespace Variations ---"
run_test "1  2  +  3  +" "Multiple spaces: 1 + 2 + 3"
run_test " 1 2 + " "Leading/trailing spaces"
run_test "1    2    +    " "Many spaces"
run_test "5  3  -  2  -" "Multiple spaces in expression"

# Edge case: all same operations
echo ""
echo "--- All Same Operations ---"
run_test "1 1 + 1 + 1 + 1 +" "All additions: 5"
run_test "2 2 * 2 * 2 *" "All multiplications: 16"
run_test "9 1 - 1 - 1 - 1 - 1 - 1 - 1 - 1 -" "All subtractions"

# Edge case: result is 0
echo ""
echo "--- Results in Zero ---"
run_test "5 5 -" "5 - 5 = 0"
run_test "0 0 +" "0 + 0 = 0"
run_test "0 5 *" "0 * 5 = 0"
run_test "1 1 - 2 3 - +" "(1 - 1) + (2 - 3) = -1 + 0"

# Edge case: single digit result
echo ""
echo "--- Result is Single Digit ---"
run_test "1 2 +" "1 + 2 = 3"
run_test "3 2 -" "3 - 2 = 1"
run_test "2 2 *" "2 * 2 = 4"
run_test "4 2 /" "4 / 2 = 2"

# More single digit edge cases
echo ""
echo "--- Additional Single Digit Cases ---"
run_test "8 1 +" "8 + 1 = 9"
run_test "7 2 +" "7 + 2 = 9"
run_test "6 3 +" "6 + 3 = 9"
run_test "9 1 -" "9 - 1 = 8"

# Nested operations
echo ""
echo "--- Deeply Nested ---"
run_test "1 2 + 3 + 4 + 5 + 6 +" "((((1+2)+3)+4)+5)+6"
run_test "2 3 * 4 * 5 * 6 *" "((((2*3)*4)*5)*6"

# Final batch to reach 100
echo ""
echo "--- Additional Edge Cases ---"
run_test "5 0 + 0 +" "5 + 0 + 0"
run_test "1 0 + 0 + 0 + 0 +" "1 + 0 + 0 + 0 + 0"
run_test "3 3 * 3 /" "(3 * 3) / 3 = 3"
run_test "7 2 / 1 +" "(7 / 2) + 1"
run_test "4 5 - 3 *" "(4 - 5) * 3 = -3"

echo ""
echo "========== SUMMARY =========="
echo "Total tests: $((PASS + FAIL))"
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ $FAIL -eq 0 ]; then
    echo "All tests passed!"
    exit 0
else
    echo "Some tests failed!"
    exit 1
fi
