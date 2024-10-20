
echo "Enter a sentence"
read str

length=${#str}
echo "Length: $length"

# Convert the sentence to lowercase
str=$(echo "$str" | tr 'A-Z' 'a-z')

# Initialize counters
vowel=0
cons=0
total=0

i=1
while [ $i -le $length ]
do
    # Extract the current character from $str (not "str")
    char=$(echo "$str" | cut -c $i)
    
    # Check if the character is a vowel
    if echo "$char" | grep -q '[aeiou]'; then
        vowel=$((vowel+1))
        total=$((total+1))
    # Check if the character is a consonant
    elif echo "$char" | grep -q '[bcdfghjklmnpqrstvwxyz]'; then
        cons=$((cons+1))
        total=$((total+1))
    fi
    
    i=$((i+1))
done

echo "Total characters (excluding spaces): $total"
echo "Vowels: $vowel"
echo "Consonants: $cons"
