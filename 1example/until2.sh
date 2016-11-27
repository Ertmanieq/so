#!/bin/sh

# parametr powinien byc nazwa uzytkownika

if [ -z $1 ]
then 
  uzytkownik="tomek"
else
  uzytkownik=$1
fi

until  who | grep $uzytkownik | wc -l > /dev/null
do 
  sleep 10
done

echo -e \\a \\b \\c
echo "****** $uzytkownik rozpoczal prace *******"

exit 0
