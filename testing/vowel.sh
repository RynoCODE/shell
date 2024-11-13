read str

length=${#str}

vowel=0
cons=0
total=0


str=$(echo $str | tr 'A-Z' 'a-z')
i=1
while [ $i -le $length ]
do
    char=$(echo $str | cut -c $i)
    if  echo $char | grep '[aeiou]' ; then
        vowel=$((vowel+1))
        total=$((total+1))
    else
        cons=$((cons+1))
        total=$((total+1))
    fi
    i=$((i+1))
done

echo "$total"
echo "$vowel"
echo "$cons"