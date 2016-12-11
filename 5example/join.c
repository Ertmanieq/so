// przyk³ad ³±czenia dwóch poleceñ za pomoc± potoku
#include <stdio.h>

int fatal(char *s) { // obs³uga b³êdu
  perror(s);
  exit(1);
}

int join(char *com1[], char *com2[]) {
  int p[2], status;

  // utwórz proces potomny do uruchomienia polecenia
  switch(fork()) {
  case -1:  // b³±d
    fatal("pierwszy fork w join");
  case 0:   // potomek
    break;
  default:  // rodzic
    wait(&status);
    return(status);
  }

  // reszta funkcji wykonywana przez proces potomny

  // utwórz potok
  if(pipe(p) == -1)
    fatal("pipe w join");
  
  // kolejny potomek 'wnuk'
  switch(fork()) {
  case -1:  // b³±d
    fatal("drugi fork w join");
  case 0:   // potomek
    // proces zapisu
    dup2(p[1], 1); // pod³±cz stdout do potoku
    // zamykamy deskryptory
    close(p[0]);
    close(p[1]);
    
    execvp(com1[0], com1);
    // je¶li execvp powróci³o, wyst±pi³ b³±d
    fatal("pierwsze wywo³anie execvp w join");
  default:
    // proces odczytu
    dup2(p[0], 0); // pod³±cz stdin do potoku
    
    close(p[0]);
    close(p[1]);
    
    execvp(com2[0], com2);
    fatal("drugie wywo³anie execvp w join");
  }
}

// program g³ówny
main() {
  char *one[4] = {"ls", "-l", "/usr/lib", NULL};
  char *two[3] = {"grep", "^d", NULL};
  int ret;

  ret = join(one, two);
  printf("join: %d\n",ret);
  exit(0);
}
