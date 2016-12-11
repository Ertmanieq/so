/* demonstracja operacji na zmiennych ¶rodowiska
 */
#include <unistd.h>
#include <stdio.h>

// wska¼nik do ¶rodowiska w funkcji main
int main(int argc, char **argv, char **env) {

  // argumenty wywo³ania (znane z C)
  if( argc == 1 ) 
    printf("Brak parametrów wywo³ania\n");
  else {
    printf("Argumenty:\t");
    while( --argc > 0) 
      printf("%s\t", *++argv);
    printf("\n");
  }
  // putenv() i getenv()
  putenv("QQ=to tylko test");
  printf("\n Pobra³em QQ   = %s\n", getenv("QQ"));
  printf("\n Pobra³em USER = %s\n", getenv("USER"));
  printf("\n");

  // lista zmiennych ¶rodowiska
  while(*env)
    printf("%s\n", *env++);
  
  // co tu siê stanie
  printf("\n Pobra³em USER = %s\n", getenv("USER"));

  return 0;
}
