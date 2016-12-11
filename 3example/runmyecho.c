/* demonstracja przekazywania parametrów do komendy wywo³ywanej 
   z execvp() */

#include <unistd.h>

main() {

  // argumenty polecenia myecho
  char * const argin[] = {"myecho", "pierwszy", "drugi", "...", (char *)0};

  execvp("./myecho", argin);
  
  /* Je¿eli execvp() nie powiod³a siê, to wykonamy nastêpuj±ce 
     komendy */
  perror("execvp: b³±d w wywo³aniu \"./myecho\"");
  exit(1);
}

