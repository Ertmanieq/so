#!/bin/sh

touch and_plik1
rm -f and_plik2

if [ -f and_plik2 ] ||  echo "jeden" ||  [ -f and_plik1 ] ||  echo "dwa"
then
  echo "warunek prawdziwy"
else
  echo "warunek falszywy"
fi

# sprzatamy
rm -f and_plik1

exit 0
