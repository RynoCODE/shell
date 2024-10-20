

echo "Enter a number to find its reverse: "
read num
reverse=0

while [ $num -ne 0 ]
do
    # Extract the last digit of the number
    digit=$((num % 10))
    
    # Build the reversed number
    reverse=$((reverse * 10 + digit))
    
    # Remove the last digit from the number
    num=$((num / 10))
done

echo "The reversed number is: $reverse"
