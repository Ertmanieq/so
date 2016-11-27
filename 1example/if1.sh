#!/bin/sh

# sprobuj wpisac pusta pore dnia

echo "Czy jest juz wieczor? (tak/nie)"
read poradnia

if [ $poradnia = "nie" ]
then
	echo "Dzien dobry"
elif [ $poradnia = "tak" ]; then
	echo "Dobry wieczor"
else
	echo "Nie rozumiem: $poradnia. Odpowiedz tak lub nie."
	exit 1
fi
exit 0
