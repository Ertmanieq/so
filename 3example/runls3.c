/* wspó³praca fork-and-exec: uruchamiamy ls jako podproces
 */
#include <sys/types.h>
#include <unistd.h>

int fatal(char *s) {
  perror(s);
  exit(1);
}

main() {

  pid_t pid;
  
  printf("---- ZACZYNAMY ----\n\n");
  switch(pid = fork()) {
  case -1: // b³±d w wywo³ania fork
    fatal("B£¡D: niepowodzenie w fork");
    break;
  case 0: // proces potomny wywo³uje exec
    execl("/bin/ls", "ls", "-l", (char *)0);
    fatal("B£¡D: niepowodzenie w execl");
    break;
  default: // proces rodzicielski czeka na zakoñczenie procesu potomnego
    wait((int *)0); // o tym potem
    printf("\n---- WSZYSTKO ZROBIONE ----\n");
    exit(0);
  }
}


