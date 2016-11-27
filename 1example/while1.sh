#!/bin/sh

# paramert powinien byc liczba

if [ -z $1 ]
then 
  liczba=10
else
  liczba=$1
fi

i=1
while [ "$i" -le $liczba ]
do 
  j=$i
  while [ "$j" -le $liczba ]
  do 
    printf "*"
    j=$(($j +1))
  done
  printf "\n"
  i=$(($i+1))
done

exit 0
