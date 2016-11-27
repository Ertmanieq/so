#!/bin/sh

# parametr powinien byc nazwa uzytkownika

if [ -z $1 ]
then 
  uzytkownik="tomek"
else
  uzytkownik=$1
fi

while [ $(who | grep $uzytkownik | wc -l) -eq 0 ]
do 
  sleep 60
done

echo -e \\a \\b \\c
echo "****** $uzytkownik rozpoczal prace *******"

exit 0
