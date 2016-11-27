#!/bin/sh

# paramert powinien byc liczba

if [ -z $1 ]
then 
  liczba=10
else
  liczba=$1
fi

i=1
until [ "$i" -gt $liczba ]
do 
  j=1
  until [ "$j" -gt $i ]
  do 
    printf "*"
    j=$(($j +1))
  done
  printf "\n"
  i=$(($i+1))
done

exit 0
