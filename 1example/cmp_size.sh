#!/bin/sh

# cmp_size - porownuje stary i nowy rozmiar katalogu
# $1  (limit)=min. rozmiar dla nowych katalogow dolaczanych do raportu
# $2 (dlimit)=min. rozmiar zmian dla starych katalogow dolaczonych do raportu
# $3  (sfile)=sciezka dostepu do pliku zawierajacego wczorajsze dane
# $4  (csize)=rozmiar biezacego katalogu
# $5   (file)=sciezka dostepu do katalogu
#       osize=poprzedni rozmiar (wydobyty z pliku sfile)
#        diff=roznica rozmiaru miedzy wczaraj i dzisiaj

if [ $# -lt 5 ]; then
  echo "Usage: cmp_size newlim oldlim data_file size dir"
  exit 1
fi
# zapamietaj parametry poczatkowe 
limit=$1; dlimit=$2; sfile=$3; file=$5; csize=$4
# uzyskaj wczorajsze dane
osize=`grep "$file\$" $sfile | awk '{print \$1}'`
if [ -z "$osize" ] ; then            # to jest nowy katalog
  if [ $csize -ge $limit ] ; then    # raportuj, jezeli rozmiar=limit
    echo -e "nowy\t$csize\t$file"
  fi
  exit 0
fi
# oblicz rozmiar zmian w stosunku do wczaoraj
if [ $osize -eq $csize ]
then
  exit 0
elif [ $osize -gt $csize ]
then
  diff=$(($osize - $csize))
else
  diff=$(($csize - $osize))
fi
# sprawdz czy rozmiar zmian jest wystarczajacy do ujecia w raporcie
if [ $diff -ge $dlimit ] ; then
  echo -e "$osize\t$csize\t$file"
fi  
