#!/bin/sh

echo g - rysuj gwiazdki
echo s - sumuj liczby
printf "Twoj wybor: "
read wybor

case "$wybor" in
  "g" | "G" | "gwiazdki" | "GWAIZDKI") ./while1.sh 24;;
  [sS] | [sS][uU][mM][uU][jJ])     ./for2.sh /dev/stdin;;
  *)                                   echo "Nie rozumiem wyboru";;
esac

exit 0
