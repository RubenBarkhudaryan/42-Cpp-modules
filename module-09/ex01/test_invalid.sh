#!/bin/bash

# Test script for invalid RPN expressions
# Usage: ./test_invalid.sh ./RPN

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
        echo "PASS (correctly rejected)"
        ((PASS++))
    else
        echo "FAIL (should have been rejected)"
        ((FAIL++))
    fi
}

echo "========== INVALID RPN CASES (100 tests) =========="
echo ""

# Too few operands
echo "--- Too Few Operands ---"
run_test "+" "Single operator: +"
run_test "-" "Single operator: -"
run_test "*" "Single operator: *"
run_test "/" "Single operator: /"
run_test "1 +" "One operand, one operator"
run_test "1 -" "One operand, one operator"
run_test "1 *" "One operand, one operator"
run_test "1 /" "One operand, one operator"
run_test "5 6 + +" "Too many operators (1 operand left)"
run_test "1 2 3 +" "Too few operators (1 operand left)"

# Too many operands
echo ""
echo "--- Too Many Operands ---"
run_test "1 2" "Two operands, no operator"
run_test "1 2 3" "Three operands, no operator"
run_test "1 2 3 4" "Four operands, no operator"
run_test "5 6 + 7" "Extra operand at end"
run_test "1 2 + 3 4" "Two operands left over"
run_test "1 2 + 3 4 +" "Multiple extra operands"
run_test "1 2 3 + + 7" "Extra operand left"

# Operator at start
echo ""
echo "--- Operator at Start ---"
run_test "+ 1 2" "Operator at beginning"
run_test "- 5 3" "Minus at start"
run_test "* 2 3" "Multiply at start"
run_test "/ 6 2" "Divide at start"
run_test "+ + 1 2" "Multiple operators at start"

# Invalid characters
echo ""
echo "--- Invalid Characters ---"
run_test "1 2 a +" "Letter: a"
run_test "1 b 2 +" "Letter in middle: b"
run_test "c 1 2 +" "Letter at start: c"
run_test "1 2 + p" "Letter: (none, but testing format)"
run_test "1 2 + @" "Special char: @"
run_test "1 & 2 +" "Special char: &"
run_test "1 2 + #" "Special char: #"
run_test "1 2 + $" "Special char: $"
run_test "1 2 + %" "Special char: %"
run_test "1 2 + ^" "Special char: ^"

# Invalid operators
echo ""
echo "--- Invalid Operators ---"
run_test "1 2 ==" "Double equals"
run_test "1 2 ++" "Double plus"
run_test "1 2 --" "Double minus"
run_test "1 2 **" "Double multiply"
run_test "1 2 //" "Double divide"

# Empty and whitespace
echo ""
echo "--- Empty and Whitespace ---"
run_test "" "Empty string"
run_test "   " "Only spaces"
run_test "  " "Two spaces"
run_test "	" "Tab"
run_test "	  	" "Mixed whitespace"

# Unbalanced expressions
echo ""
echo "--- Unbalanced Expressions ---"
run_test "1 2 + 3 + +" "Extra operator at end"
run_test "1 2 + + 3" "Operator without operand"
run_test "1 + 2 3" "Infix notation (not RPN)"
run_test "1 + 2 +" "Infix style operation"
run_test "+ + 1 2 3" "Too many operators"

# Edge case: only operators
echo ""
echo "--- Only Operators ---"
run_test "+" "Single +"
run_test "-" "Single -"
run_test "*" "Single *"
run_test "/" "Single /"
run_test "+ - * /" "All operators"
run_test "+ + + +" "Multiple +"
run_test "- - - -" "Multiple -"
run_test "* * * *" "Multiple *"
run_test "/ / / /" "Multiple /"
run_test "+ - + -" "Mixed operators"

# Incomplete expressions
echo ""
echo "--- Incomplete Expressions ---"
run_test "1 2" "No operator"
run_test "1 2 3 + 4" "Extra operands"
run_test "5 4 3 2 +" "Too many leading operands"

# Operators without pairing
echo ""
echo "--- Operators Without Pairing ---"
run_test "1 + 2" "Infix: 1 + 2 (invalid RPN)"
run_test "1 - 2" "Infix: 1 - 2 (invalid RPN)"
run_test "5 * 6" "Infix: 5 * 6 (invalid RPN)"
run_test "8 / 2" "Infix: 8 / 2 (invalid RPN)"

# Multiple issues
echo ""
echo "--- Multiple Issues Combined ---"
run_test "a b + c" "Invalid chars and unbalanced"
run_test "1 2 + + a" "Invalid char and extra operator"
run_test "+ - 1 2 3" "Multiple operators at start"

# Consecutive operators
echo ""
echo "--- Consecutive Operators ---"
run_test "1 + +" "Consecutive operators"
run_test "1 - -" "Consecutive minus"
run_test "1 * *" "Consecutive multiply"
run_test "1 / /" "Consecutive divide"
run_test "1 2 + -" "Operators without proper operands"
run_test "1 2 - +" "Operators without proper operands"
run_test "1 2 + * 3" "Consecutive operators after operation"

# Too many operators in sequence
echo ""
echo "--- Too Many Operators ---"
run_test "1 2 3 + + + 4" "Three operators without enough operands"
run_test "1 2 + + + +" "Multiple consecutive operators"
run_test "5 6 + + + 7 8" "Multiple operators with gaps"

# Wrong operator placement
echo ""
echo "--- Wrong Operator Placement ---"
run_test "1 2 3 + + 4 5" "Valid start, then invalid"
run_test "+ 1 2 3 +" "Operator at start"
run_test "1 2 + 3 4" "Extra operands at end"

# Edge cases with zero (structurally invalid)
echo ""
echo "--- Structurally Invalid Even with Valid Numbers ---"
run_test "0 0 0 0" "Multiple zeros, no operators"
run_test "0 1 2 3" "Multiple zeros and numbers, no operators"

# Mixed valid structure breakers
echo ""
echo "--- Structure Breakers ---"
run_test "1 2 a" "Valid start, invalid char"
run_test "a 1 2 +" "Invalid char at start"
run_test "1 a 2 +" "Invalid char in middle"

# Excessive operators
echo ""
echo "--- Excessive Operators ---"
run_test "1 2 + + + + +" "Many consecutive operators"
run_test "- - - - 1 2" "Many minus at start"

# Division edge cases (structurally invalid, not runtime)
echo ""
echo "--- Invalid Structure (Not Division by Zero) ---"
run_test "1 2 3 4 5 / / /" "Too many divisions"
run_test "1 2 / / / 3 4" "Multiple divisions"

# Additional invalid cases to reach 100
echo ""
echo "--- Multidigit Numbers (Invalid) ---"
run_test "10 20 +" "Double digit numbers"
run_test "12 34 +" "Two-digit numbers"
run_test "99 88 +" "Large two-digit numbers"
run_test "100 200 +" "Three-digit numbers"
run_test "5 10 +" "Five and ten"
run_test "123 456 +" "Three-digit numbers"
run_test "10 20 30 + +" "Multiple multidigit numbers"

# Braces and parentheses (Invalid)
echo ""
echo "--- Braces and Parentheses (Invalid) ---"
run_test "(1 2 +)" "Parentheses around expression"
run_test "(1) (2) +" "Parentheses around operands"
run_test "( 1 2 + )" "Parentheses with spaces"
run_test "{1 2 +}" "Braces around expression"
run_test "[1 2 +]" "Square brackets"
run_test "1 2 (+)" "Parentheses as operator"
run_test "1 2 ()" "Empty parentheses"
run_test "()" "Only parentheses"
run_test "{}" "Only braces"
run_test "[]" "Only brackets"

# More invalid character cases
echo ""
echo "--- Additional Invalid Characters ---"
run_test "1 2 + ." "Decimal point"
run_test "1 2 + !" "Exclamation"
run_test "1 2 + ?" "Question mark"
run_test "1 2 + :" "Colon"
run_test "1 2 + ;" "Semicolon"
run_test "1 2 + ," "Comma"
run_test "1.5" "Decimal number"
run_test "1 2.5 +" "Decimal with operations"

# Additional structural issues
echo ""
echo "--- Additional Structural Cases ---"
run_test "1 2 3 4 5 6 7 8 9" "Too many operands"
run_test "+ - * /" "Only operators"
run_test "1 1 1 1 1 1 1 1 1" "Only operands, no operators"

echo ""
echo "========== SUMMARY =========="
echo "Total tests: $((PASS + FAIL))"
echo "Passed: $PASS"
echo "Failed: $FAIL"

if [ $FAIL -eq 0 ]; then
    echo "All invalid cases correctly rejected!"
    exit 0
else
    echo "Some invalid cases were not rejected!"
    exit 1
fi
