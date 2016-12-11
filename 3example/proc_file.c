/* pokazuje obs³ugê wspólnych plików przez procesy
   zak³adamy, ¿e "data" jest plikiem o najmniej 20 znakach
*/
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int fatal(char *s) {
  perror(s);
  exit(1);
}

// drukuje pozycjê pliku i zawarto¶æ bufora
int printpos(const char *string, int filedes, char *buf) {
  off_t pos;
  // badamy pozycjê w pliku przez wykorzystanie wyniku funkcji 
  // lseek z przesuniêciem o 0 bajtów od aktualnej pozycji
  if((pos = lseek(filedes, 0, SEEK_CUR)) == -1)
    fatal("B£¡D: niepowodzenie lseek");
  printf("%s:%ld:%s\n", string, pos, buf);
}

// program g³ówny
main() {
  int fd;       // deskryptor pliku
  pid_t pid;    // ID procesu
  char buf[10]; // bufor dla danych pliku
 
  if((fd = open("data", O_RDONLY)) == -1) 
    fatal("B£¡D: otwarcie pliku");
  
  read(fd, buf, 10); // czytamy 10 znaków

  printpos("PRZED: fork()", fd, buf);

  // tworzymy potomka
  switch(pid = fork()) {
  case -1: // b³±d
    fatal("B£¡D: niepowodzenie w fork");
    break;
  case 0: // proces potomny
    printpos("POTOMNY: przed read", fd, buf);
    read(fd, buf, 10); // czytamy 10 znaków
    printpos("POTOMNY: po read", fd, buf);
    break;
  default: // proces rodzicielski
    wait((int *)0); // o tym potem
    printpos("RODZICIELSKI: po wait", fd, buf);
  }
}
/*
  Zadanie: Sprawd¼, co dzieje siê wewn±trz procesu rodzicielskiego, 
           je¶li proces potomny zamknie deskryptor pliku dziedziczony 
	   za po¶rednictwem fork()?
	   Czy dla procesu rodzicielskiego plik ten pozostanie otwarty,
	   czy te¿ zostanie zamkniêty?
*/
  
