
if [ $# -ne 3 ]; then
    echo "Please provide exactly 3 numbers as command line arguments."
    exit 1
fi

num1=$1
num2=$2
num3=$3

# Find maximum
if [ $num1 -ge $num2 ] && [ $num1 -ge $num3 ]; then
    max=$num1
elif [ $num2 -ge $num1 ] && [ $num2 -ge $num3 ]; then
    max=$num2
else
    max=$num3
fi

# Find minimum
if [ $num1 -le $num2 ] && [ $num1 -le $num3 ]; then
    min=$num1
elif [ $num2 -le $num1 ] && [ $num2 -le $num3 ]; then
    min=$num2
else
    min=$num3
fi

echo "Maximum: $max"
echo "Minimum: $min"
