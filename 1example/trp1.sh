#!/bin/sh

# ustawiamy obsluge sygnalu INT

trap 'rm -f /tmp/plik_tymczasowy_$$' INT

echo Tworzenie pliku /tmp/plik_tymczasowy_$$
date > /tmp/plik_tymczasowy_$$

echo "Nacisnij Ctrl+C, aby przerwac ..."
while [ -f /tmp/plik_tymczasowy_$$ ] 
do 
  echo "   Plik istnieje"
  sleep 1
done

echo Plik juz nie istnieje

# teraz to samo bez obslugo sygnalu INT

trap - INT

echo Tworzenie pliku /tmp/plik_tymczasowy_$$
date > /tmp/plik_tymczasowy_$$

echo "Nacisnij Ctrl+C, aby przerwac ..."
while [ -f /tmp/plik_tymczasowy_$$ ] 
do 
  echo "   Plik istnieje"
  sleep 1
done

echo Nigdy tu nie dojdziemy

exit 0
