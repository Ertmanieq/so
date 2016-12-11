// przyk�ad nieblokuj�cych zapis�w i odczyt�w

#include <fcntl.h>
#include <errno.h>

#define MSGSIZE 6

char *msg1 = "hello";
char *msg2 = "bye!!";

int fatal(char *s) { // obs�uga b��du
  perror(s);
  exit(1);
}

int parent(int p[2]) { // kod rodzica
  int nread;
  char buf[MSGSIZE];

  close(p[1]);
  for(;;) {
    switch(nread = read(p[0], buf, MSGSIZE)) {
    case -1: 
      // sprawd� czy jest co� w potoku
      if(errno == EAGAIN) {
	printf("potok pusty\n");
	sleep(1);
	break;
      }
      else
	fatal("wywo�anie read");
    case 0:
      // potok zosta� zamkni�ty
      printf("Koniec rozmowy\n");
      exit(0);
    default:
      printf("MSG = %s\n",buf);
    }
  }
}

int child(int p[2]) { // kod potomka
  int count;

  close(p[0]);
  for(count = 0; count < 3; count++) {
    write(p[1], msg1, MSGSIZE);
    sleep(3);
  }
  // wy�lij komunikat ko�cowy
  write(p[1], msg2, MSGSIZE);
  exit(0);
}

// program g��wny
main() {
  int pfd[2];
  
  // otw�rz potok
  if(pipe(pfd) == -1)
    fatal("wywo�anie pipe");

  // ustaw znacznik O_NONBLOCK dla p[0]
  if( fcntl(pfd[0], F_SETFL, O_NONBLOCK) == -1)
    fatal("wywo�anie fcntl");
  
  switch(fork()) {
  case -1: // b��d
    fatal("wywo�anie fork");
  case 0:  // potomek
    child(pfd);
  default: // rodzic
    parent(pfd);
  }
}
