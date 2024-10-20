
echo "Enter numerator: "
read num1
echo "Enter denominator: "
read num2

if [ $num2 -eq 0 ]; then
    echo "Error: Division by zero is not allowed."
else
    result=$((num1 / num2))
    echo "Result: $result"
fi
