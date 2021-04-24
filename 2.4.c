#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void parentTask()
{
 printf("Job Done...\n");
}

int main(void)
{
 for(int i = 1; i < 5; i++)
 { 
  pid_t pid = fork();
  char name[50];

  if(pid == 0)
  {
   printf(" Please Enter your name > " );
   scanf("%s", name);
   printf(" Your name is %s.\n", name);
   exit(0);
  }
  else 
  {
    printf("Waiting for child processes to finish...\n");
    wait(NULL);
    parentTask();
  }
 }
 return EXIT_SUCCESS;
}

    
