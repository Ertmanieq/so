// przyk�ad ��czenia dw�ch polece� za pomoc� potoku
#include <stdio.h>

int fatal(char *s) { // obs�uga b��du
  perror(s);
  exit(1);
}

int join(char *com1[], char *com2[]) {
  int p[2], status;

  // utw�rz proces potomny do uruchomienia polecenia
  switch(fork()) {
  case -1:  // b��d
    fatal("pierwszy fork w join");
  case 0:   // potomek
    break;
  default:  // rodzic
    wait(&status);
    return(status);
  }

  // reszta funkcji wykonywana przez proces potomny

  // utw�rz potok
  if(pipe(p) == -1)
    fatal("pipe w join");
  
  // kolejny potomek 'wnuk'
  switch(fork()) {
  case -1:  // b��d
    fatal("drugi fork w join");
  case 0:   // potomek
    // proces zapisu
    dup2(p[1], 1); // pod��cz stdout do potoku
    // zamykamy deskryptory
    close(p[0]);
    close(p[1]);
    
    execvp(com1[0], com1);
    // je�li execvp powr�ci�o, wyst�pi� b��d
    fatal("pierwsze wywo�anie execvp w join");
  default:
    // proces odczytu
    dup2(p[0], 0); // pod��cz stdin do potoku
    
    close(p[0]);
    close(p[1]);
    
    execvp(com2[0], com2);
    fatal("drugie wywo�anie execvp w join");
  }
}

// program g��wny
main() {
  char *one[4] = {"ls", "-l", "/usr/lib", NULL};
  char *two[3] = {"grep", "^d", NULL};
  int ret;

  ret = join(one, two);
  printf("join: %d\n",ret);
  exit(0);
}
