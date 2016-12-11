/* demonstracja u¿ycia "execv()" do uruchomienia "ls"
 */
#include <unistd.h>

main() {

  // argumenty zadane jako wska¼nik do listy napisów
  char * const av[] = {"ls", "-li", (char *)0};

  printf("Zaraz wykonam ls ... \n");

  execv("/bin/ls", av);
  
  /* Je¿eli execv() nie powiod³a siê, to wykonamy nastêpuj±ce 
     komendy */
  perror("execv: b³±d w wywo³aniu \"ls -l\"");
  exit(1);
}

/* Reszta funkcji rodziny exec() jest podobna 
   i zapoznanie siê ze sposobem ich u¿ycia jest zadaniem domowym */


