
echo "Enter a number to find the sum of its digits: "
read a
sum=0

while [ $a -ne 0 ]
do
    # Extract the last digit
    digit=$((a % 10))
    
    # Add the digit to sum
    sum=$((sum + digit))
    
    # Remove the last digit from the number
    a=$((a / 10))
done

echo "The sum of digits is: $sum"
