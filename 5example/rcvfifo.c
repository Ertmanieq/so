// odbiera komunikaty przez FIFO
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#define MSGSIZE  63

char *fifo = "fifo";

int fatal(char *s) { // obs³uga b³êdu
  perror(s);
  exit(1);
}

main(int argc, char **argv) {
  int fd;
  char msgbuf[MSGSIZE+1];

  // utwórz fifo je¶li jeszcze nie istnieje
  if(mkfifo(fifo, 0666) == -1) {
    if(errno != EEXIST)
      fatal("rcvfifo: mkfifo");
  }
  
  // otwórz fifo do odczytu i zapisu
  if((fd = open(fifo, O_RDWR)) < 0)
    fatal("b³±d otwarcia fifo");
  
  // odbierz komunikaty
  for( ; ; ) {
    if(read(fd, msgbuf, MSGSIZE+1) < 0)
      fatal("b³±d odczytu wiadomo¶ci");
    
    // tu server mo¿e robiæ CO¦ z komunikatem

    printf("otrzyma³em: %s\n", msgbuf);
  }
}
