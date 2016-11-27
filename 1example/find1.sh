find / -type d \( -perm -o=w -fprint allwrite , \
       -perm -o=x -fprint allexec \) 2>/dev/null
     
echo "Katalogi do pisania dla wszystkich:"
cat allwrite
echo ""
echo "Katalogi do przeszukiwania dla szystkich:"
cat allexec
