#include <stdio.h> // input output
#include <stdlib.h> // pour fonction exet
#include <sys/types.h> // pour le type pid_t
#include <sys/wait.h> // por fonction wait();
#include <unistd.h> // pour gestion de processus aux linux


int main()
{
  pid_t pid = fork();
    if(pid == 0){
	printf("je suis le processus fils :%d \n",getpid());
    }
    else if(pid > 0){
	printf("je suis le processus  parent  :%d \n ",getppid());
    }
    else{
	printf("Erreur \n");
    }
return 0;
}
