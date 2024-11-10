#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

     int fd[2] ;
     pid_t p1, p2;
     char message[] = "hello world" ;
     char b[30];
     pipe(fd);
     if(pipe(fd) == -1){
          printf("erruer !");
          exit(1);
     }

    // processus 1
     p1 = fork();
     if(p1 == -1){
          printf("Erreur de creation de processus de fils 1\n");
          exit(1);
     }
     else if(p1 == 0){
          close(fd[1]);
          read(fd[0],b,sizeof(b));
          for(int i = 0; i < strlen(b);i++){
            b[i] = toupper(b[i]);
          }   
          printf("le processus de fils 1 : %s \n",b);
          close(fd[0]);
          exit(0);
     }
    // processus 2

     p2 = fork();
     if(p2 == -1){
          printf("Erreur de creation de processus de fils 2 \n");
          exit(1);
     }
     else if(p2 == 0){
          close(fd[1]);
          read(fd[0],b,sizeof(b));
          for( int i = 0; i < strlen(b);i++){
            b[i] = tolower(b[i]);
          }
          exit(0);
     }



    close(fd[0]);
    printf("enter un message : \n");
    scanf("%s",message);
    write(fd[1],message,30);
    close(fd[1]);
    waitpid(p1,NULL,0);
    waitpid(p2,NULL,0);
    exit(0);

     return 0;
}  