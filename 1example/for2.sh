#!/bin/sh

# pierszy parametr to nazwa pliku z liczbami do sumowania
#
# wywolaj np.: for2.sh liczby 
# lub:         for2.sh /dev/stdin

suma=0
for liczba in $(cat $1)
do 
	suma=$(($suma + $liczba))
done
echo "Suma = "$suma

exit 0
