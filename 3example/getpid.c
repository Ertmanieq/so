/* program odczytuje PID swój i rodzica
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

main() {

  pid_t pid  = getpid();
  pid_t ppid = getppid();

  printf(" PID  = %d\n", pid );
  printf(" PPID = %d\n", ppid );
}

/* porównaj otrzymane wyniki z wynikiem komendy 
     echo $$ 
   oraz 
     ps -u
*/
