#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

     int fd[2] ;
     pid_t p1, p2;
     char message[30];
     pipe(fd);
     if(pipe(fd) == -1){ 
          printf("erruer !");
          exit(1);
     }

     // creation de la processus de fils 1
     p1 = fork();
     if(p1 == -1){
          printf("Erreur de creation de processus de fils 1\n");
          exit(1);
     }
     else if(p1 == 0){
          close(fd[1]);
          read(fd[0],message,30);
          printf("le message est : %s ", message);
          exit(0);
     }
      
     p2 = fork();
     if(p2 == -1){
          printf("Erreur de creation de processus de fils 2 \n");
          exit(1);
     }
     else if(p2 == 0){
          close(fd[0]);
          sprintf(message,"hello");
          write(fd[1],message,30);
          exit(0);
     }

     waitpid(p1,NULL,0);
     waitpid(p2,NULL,0);
     exit(0);

     return 0;
}
