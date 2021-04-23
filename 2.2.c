#include <stdlib.h>    /*needed to define exit()*/
#include <unistd.h>    /*needed to define fork() and getpid()*/
#include <stdio.h>     /* needed to define printf() */
#include <sys/wait.h>  /* needed for wait() to break all process for child */

int main(int argc,char**argv)
{
  int pid;       /*pid process*/


  switch (pid=fork())
  {
   case 0:                  /*a fork returns 0 to the child*/

      printf("I am the child process: pid=%d\n", getpid());
      break;

   default:                /* a fork returns a pid to the parent*/

      wait(NULL);
      printf("I am the parent process: pid=%d, child pid=%d\n", getpid(), pid);
      break;

   case -1:               /* Error not parent or child */

      perror("fork");
      exit(1);

  }
 exit(0);
}
