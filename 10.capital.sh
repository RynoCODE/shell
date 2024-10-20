
# Prompt user for input
echo "Enter a sentence: "
read sentence

# Convert to uppercase
uppercase=$(echo "$sentence" | tr 'a-z' 'A-Z')
echo "Uppercase: $uppercase"

# Convert to lowercase
lowercase=$(echo "$sentence" | tr 'A-Z' 'a-z')
echo "Lowercase: $lowercase"
