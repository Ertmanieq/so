#!/bin/sh

zmienna="wartosc globalna"

lokalnie () {
  local zmienna="wartosc lokalna"
  echo Jestem funkcja ze zmienna lokalna: $zmienna.
}

echo \$zmienna = $zmienna
echo
lokalnie
echo
echo \$zmienna = $zmienna

exit 0
