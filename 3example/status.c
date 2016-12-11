/* przyk³ad uzyskania statusu wyj¶cia potomka
 */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int fatal(char *s) {
  perror(s);
  exit(1);
}

main() {
  pid_t pid;
  int status, exit_status;

  if((pid = fork()) < 0) 
    fatal("B£¡D: nipowodzenie w fork");
  if(pid == 0) { // potomek
    // zawieszamy wykonanie na 4 sek.
    printf("Potomek: %d\n", getpid());
    sleep(4);
    exit(5);  // wyj¶cie z warto¶ci± niezerow±
  }
  // je¿eli jeste¶my tu, to musi byæ rodzic
  printf("Rodzic : %d\n", getpid());
  if((pid = wait(&status) ) == -1) {
    perror("B£¡D: niepowodzenie w wait");
    exit(2);
  }
  // test zakoñczenia potomka
  if(WIFEXITED(status)) {
    exit_status = WEXITSTATUS(status);
    printf("Kod wyj¶cia procesu %d to %d\n", pid, exit_status);
  }
  exit(0);
}
