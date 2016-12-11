// przyk³ad prostego potoku przesy³aj±cego dane
// pomiêdzy procesem rodzicielskim i potomnym
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

// rozmiar komunikatu - zawiera tak¿e koñcowe 0
#define MSGSIZE 16

char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

main() {
  char inbuf[MSGSIZE];
  int p[2], j;
  pid_t pid;

  // otwieramy potok
  if(pipe(p) == -1) {
    perror("utworzenie potoku");
    exit(1);
  }
  switch(pid = fork()) {
  case -1: 
    perror("utworzenie procesu potomnego");
    exit(2);
  case 0: // potomek pisze do potoku
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
    break;
  default: // rodzic czyta z potoku
    for(j = 0; j < 3; j++) {
      read(p[0], inbuf, MSGSIZE);
      printf("%s\n", inbuf);
    }
    wait(NULL);
  }
  exit(0);
}
    
