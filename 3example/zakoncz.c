/* demonstracja funkcji czyszcz±cych
 */
#include <stdlib.h>


void funkcja1(void) {
  printf("Pierwsza funkcja czyszcz±ca\n");
}

void funkcja2(void) {
  printf("Druga    funkcja czyszcz±ca\n");
}

void funkcja3(void) {
  printf("Trzecia  funkcja czyszcz±ca\n");
}


main() {
  void ((*func)(void));
  
  printf("Przed rejestracj±\n");
  // rejestracja czyszczenia
  atexit(funkcja1);
  atexit(funkcja2);
  atexit(funkcja3);
  printf("Po    rejestracji\n");
  printf("Przed exit\n");
  // koñczymy
  exit(0);
  printf("Po    exit\n"); // tego nie zobaczymy
}
  
