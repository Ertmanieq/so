#!/bin/sh

# ckpwd - sprawdzanie pliku hasel (wykonuj jako root)

umask 077
cd . # przejdz do katalogu, gdzie przechowywane sa wyniki tego skryptu
echo ">>> Plik z haslami sprawdzony `date` "
echo

echo "*** Konta bez hasel:"
grep '^[^:]*::' /etc/passwd
if [ $? -eq 1 ]   # grep nic nie znalazl
then
  echo "Nic nie ma"
fi
echo

echo "*** UID=0 lub GID=0 dla kont innych niz root:"
grep ':00*:' /etc/passwd | \
  awk -F: 'BEGIN         {n=0}
           $1!="root"    {print $0 ; n=1}
           END           {if (n=0) print "Nic nie ma"}'
echo

sort /etc/passwd > tmp1
sort </etc/passwd.OLD >tmp2   # opg to zachowana kopia
echo "*** Konta dodane:"
comm -23 tmp[1-2] # linie tylko w /etc/passwd
echo
echo "*** Konta usuniete:"
comm -13 tmp[1-2] # linie tylko w ./etc/passwd.OLD
echo 
rm -f tmp[1-2]

echo "*** Ochrona pliku hasel:"
echo "-rw-r--r--    1 root     wheel         >>> poprawne wartosci"
ls -l /etc/passwd

echo 
echo ">>> Koniec raportu."
echo
