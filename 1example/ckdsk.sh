#!/bin/sh

# chkdsk - sprawdza rozmiary wielu katalogow z roznymi wartosciami granicznymi

du_it () {
#  $1=wartosc graniczna dla nowych katalogow (w blokach)
#  $2=wartosc graniczna zmian dla starych katalogow (w blokach)
#  $3=katalog ; $4=wskazniki dla du

 du $4 $3 > du.tmp
 cat du.tmp | xargs -n2 ./cmp_size.sh $1 $2 du.sav
 cat du.tmp >> du.log; rm du.tmp
}

umask 077
rm -f du.log du.tmp 2>&1 > /dev/null
if [ ! -s du.sav ] ; then 
  echo "run_cmp; nie znaleziono pliku ze starymi danymi"
  exit 1
fi
echo "Dzienny raport wykorzystania dysku z dnia `date`"
echo
df
echo
echo -e "Stary\tNowy"
echo -e "Rozmiar\tRozmiar\tKatalog"
echo "------------------------------------------------------"
du_it  1  100  /home/tomek/
du_it  1  100  /usr/lib
du_it  1 1000  /home/\* -s
echo "------------------------------------------------------"
echo
mv -f du.log du.sav
exit 0
