/* demonstracja u¿ycia "execl()" do uruchomienia "ls"
 */
#include <unistd.h>

main() {
  printf("Zaraz wykonam ls ... \n");

  execl("/bin/ls", "ls", "-l", (char *) 0);
  
  /* Je¿eli execl() nie powiod³a siê, to wykonamy nastêpuj±ce 
     komendy */
  perror("execl: b³±d w wywo³aniu \"ls -l\"");
  exit(1);
}


