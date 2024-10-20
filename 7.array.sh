
list=("apple" "banana" "cherry" "date" "elderberry")
list_size=${#list[@]}

for ((i=0; i<list_size; i++))
do
    echo "Index: $i, Value: ${list[$i]}"
done
