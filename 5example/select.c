// przyklad serwera zbudowanego na funkcji select
// odpytuj±cego potoki procesów potomnych
#include <sys/time.h>
#include <sys/wait.h>
#include <stdio.h>

#define MSGSIZE  6

char *msg1 = "hello";
char *msg2 = "bye!!";

int fatal(char *s) { // obs³uga b³êdu
  perror(s);
  exit(1);
}

// rodzic nas³uchuje na wszystkich trzech potokach
void parent(int p[3][2]) { // kod rodzica
  char buf[MSGSIZE], ch;
  fd_set set, master;
  int i;

  // zamknij wszystkie niepotrzebne deskryptory potoków
  for(i = 0; i < 3; i++)
    close(p[i][1]);
  
  // ustaw maski bitowe dla funkcji select
  FD_ZERO(&master);
  FD_SET(0, &master);
  for(i = 0; i < 3; i++)
    FD_SET(p[i][0], &master);

  // funkcja select wywo³ana bez czasu oczekiwania
  // powinna siê blokowaæ a¿ do wyst±pienia zdarzenia
  while(set = master, select(p[2][0]+1, &set, NULL, NULL, NULL) > 0) {
    // nie zapominamy o stdin tj. fd=0
    if(FD_ISSET(0, &set)) {
      printf("Z stdin: ");
      read(0, &ch, 1);
      printf("%c\n",ch);
    }
    for(i = 0; i < 3; i++) {
      if(FD_ISSET(p[i][0], &set)) {
	if(read(p[i][0], buf, MSGSIZE)>0) {
	  printf("Komunikat od potomka #%d\n",i);
	  printf("MSG = %s\n", buf);
	}
      }
    }
    // serwer powinien powróciæ do programu g³ównego je¶li nie ma ju¿ dzieci
    if(waitpid(-1, NULL, WNOHANG) == -1)
      return;
  }
}

int child(int p[2]) {
  int count;
  
  close(p[0]);

  for(count = 0; count < 2; count++) {
    write(p[1], msg1, MSGSIZE);
    // czekaj trochê ...
    sleep(getpid() % 4);
  }
  // wy¶lij koñcowy komunikat
  write(p[1], msg2, MSGSIZE);
  exit(0);
}

// program g³ówny
main() {
  int pip[3][2];
  int i;

  // utwórz 3 potoki komunikacyjne i 3 potomki
  for(i = 0; i < 3; i++) {
    if(pipe(pip[i]) == -1) 
      fatal("wywo³anie pipe");
    switch(fork()) {
    case -1: // b³±d
      fatal("wywo³anie fork");
    case 0:  // potomek
      child(pip[i]);
    }
  }
  parent(pip);

  exit(0);
}
