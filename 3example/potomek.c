/* demonstaracja dzia³ania funkcji fork
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (void) {
  pid_t child;

  if( !(child=fork()) ) {
    printf("\n Proces potomny: PID=%d, PPID=%d\n",getpid(),getppid());
    exit(0);
  }
  printf("\n Proces macierzysty. Potomkiem jest %d. PID=\%d, PPID=%d\n", 
	 child,getpid(),getppid());

  return 0;
}
