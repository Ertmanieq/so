# deklaracja trzech zmiennych calkowitych
declare -i a=1   
declare -i b=2
declare -i c=0
# deklaracja zmiennej tylko do odczytu
declare -r zm_ro=12

# obliczenie dla zadeklarowanych zmiennych calkowitych
c=a+b

# zmienne niezadeklarowane
x=11
y=22
# obliczenie dla niezadeklarowanych zmiennych
#z=$(($x+$y))
# jaki bedzie wynik, gdy pow. linie zastapimy przez:
 z=x+y

echo a=$a
echo b=$b
echo c=$c
echo x=$x
echo y=$y
echo z=$z

declare -p zm_ro
