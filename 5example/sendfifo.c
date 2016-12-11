// wysy�a komunikaty przez FIFO
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#define MSGSIZE  63

char *fifo = "fifo";

int fatal(char *s) { // obs�uga b��du
  perror(s);
  exit(1);
}

main(int argc, char **argv) {
  int fd, j, nwrite;
  char msgbuf[MSGSIZE+1];

  if(argc < 2) {
    fprintf(stderr, "U�ycie: sendfifo msg1 .... \n");
    exit(1);
  }
  // otw�rz fifo z ustawionym O_NONBLOCK
  if((fd = open(fifo, O_WRONLY | O_NONBLOCK)) < 0)
    fatal("b��d otwarcia fifo");
  
  // wy�lij komunikat
  for(j = 1; j < argc; j++) {
    if(strlen(argv[j]) > MSGSIZE) {
      fprintf(stderr, "wiadomo�� za d�uga: %s\n", argv[j]);
      continue;
    }
    strcpy(msgbuf, argv[j]);
    if((nwrite = write(fd, msgbuf, MSGSIZE)) == -1)
      fatal("b��d zapisu komunikatu");
  }
  exit(0);
}
