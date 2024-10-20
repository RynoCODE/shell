
# Prompt user for the number of elements
echo "Enter the number of elements: "
read n

# Declare an array
declare -a arr

# Read numbers from the user into the array
echo "Enter $n numbers: "
for (( i=0; i<n; i++ ))
do
    read arr[i]
done

# Display the original array
echo "Original array: ${arr[*]}"

# Bubble Sort Algorithm
for (( i=0; i<n-1; i++ ))
do
    for (( j=0; j<n-i-1; j++ ))
    do
        if [ ${arr[j]} -gt ${arr[$((j+1))]} ]; then
            # Swap the elements
            temp=${arr[j]}
            arr[$j]=${arr[$((j+1))]}
            arr[$((j+1))]=$temp
        fi
    done
done

# Display the sorted array
echo "Sorted array: ${arr[*]}"
