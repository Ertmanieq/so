#!/bin/bash

power () {
  local wynik=1
  local licznik=$2
  while [ $licznik -ne 0 ]
  do
    wynik=$(($wynik * $1))
    licznik=$(($licznik - 1))
  done
  echo $wynik
}

kwadrat=`power $1 2`

echo "Kwadrat $1   : $kwadrat"
echo "Potega($1,$2) : `power $1 $2`"

potega=`power $1 $2`
potega=`power $potega $2`
echo "Potega2($1,$2): $potega"

exit 0
