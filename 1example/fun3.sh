#!/bin/bash

wybor () {
  while :
  do 
    echo t/T  - Tak
    echo n/N  - Nie
    echo -n "wybierz: "
    read opcja

    case "$opcja" in 
      [tT] )  return 0;;
      [nN] )  return 1;;
      * )  echo Wybierz opcje t/n 
    esac
  done
}

if wybor 
then
   echo opcja tak
else
   echo opcja nie
fi

exit 0
