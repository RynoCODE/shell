

# Prompt user for input
echo "Enter a number: "
read num

# Check if number is less than 2 (not prime)
if [ $num -lt 2 ]; then
    echo "$num is not a prime number."
    exit 0
fi

# Flag variable to indicate if number is prime
is_prime=1

# Check divisibility from 2 to sqrt(num)
for ((i=2; i*i<=num; i++))
do
    if [ $((num % i)) -eq 0 ]; then
        is_prime=0
        break
    fi
done

# Check if is_prime flag is still 1 (means number is prime)
if [ $is_prime -eq 1 ]; then
    echo "$num is a prime number."
else
    echo "$num is not a prime number."
fi
