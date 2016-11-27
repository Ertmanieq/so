#!/bin/sh

# zapamietujemy dotychczasowe ustawienia
 
PATH_OLD=$PATH
PS1_OLD=$PS1

# ustawiamy nowe

PATH=$PATH:.
PS1="(\#)\t \u@\h:\w>"

