/* demonstracja funkcji czyszczących
 */
#include <stdlib.h>


void funkcja1(void) {
  printf("Pierwsza funkcja czyszcząca\n");
}

void funkcja2(void) {
  printf("Druga    funkcja czyszcząca\n");
}

void funkcja3(void) {
  printf("Trzecia  funkcja czyszcząca\n");
}


main() {
  void ((*func)(void));
  
  printf("Przed rejestracją\n");
  // rejestracja czyszczenia
  atexit(funkcja1);
  atexit(funkcja2);
  atexit(funkcja3);
  printf("Po    rejestracji\n");
  printf("Przed exit\n");
  // kończymy
  exit(0);
  printf("Po    exit\n"); // tego nie zobaczymy
}
  
