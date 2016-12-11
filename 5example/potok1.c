// przyk�ad prostego potoku wysy�aj�cego dane do siebie samego
#include <unistd.h>
#include <stdio.h>

// rozmiar komunikatu - zawiera tak�e ko�cowe 0
#define MSGSIZE 16

char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

main() {
  char inbuf[MSGSIZE];
  int p[2], j;
  
  // otwieramy potok
  if(pipe(p) == -1) {
    perror("utworzenie potoku");
    exit(1);
  }

  // piszemy do potoku
  write(p[1], msg1, MSGSIZE);
  write(p[1], msg2, MSGSIZE);
  write(p[1], msg3, MSGSIZE);

  // odczytujemy z potoku
  for(j = 0; j < 3; j++) {
    read(p[0], inbuf, MSGSIZE);
    printf("%s\n", inbuf);
  }
  exit(0);
}
