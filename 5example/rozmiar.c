// przyk³ad badania wielko¶ci potoku

#include <signal.h>
#include <unistd.h>
#include <limits.h>

int count;

// procedura obs³ugi sygna³u
void alrm_action(int signo) {
  printf("Zapis zablokowany po %d znakach\n", count);
  exit(0);
}

main() {
  int p[2];
  int pipe_size;
  char c = 'x';

  static struct sigaction act;
  
  // przygotuj program obs³ugi sygna³u
  act.sa_handler = alrm_action;
  sigfillset(&(act.sa_mask));

  // utwórz potok
  if(pipe(p) == -1) {
    perror("wywo³anie pipe");
    exit(1);
  }
  // okre¶l wielko¶æ potoku
  pipe_size = fpathconf(p[0], _PC_PIPE_BUF);
  printf("Maksymalny rozmiar potoku: %d bajtów\n", pipe_size);

  // ustaw program obs³ugi sygna³u
  sigaction(SIGALRM, &act, NULL);

  while(1) {
    // ustaw alarm
    alarm(10);
    // zapisz do potoku
    write(p[1], &c, 1);
    // wy³±cz alarm
    alarm(0);
    
    if((++count % 1024) == 0)
      printf("%d znaków w potoku\n", count);
  }
}

