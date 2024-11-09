#include <stdio.h> // input / output
#include <stdlib.h> // exit()
#include <unistd.h> // pour gestion des processus
#include <sys/types.h> // pour le type pid_t
#include <sys/wait.h> // les fonction comme wait()

#define NB_PROCESS 10 // le nomber de fils a cree 
#define NB_ITERATION 10 // nomber de affichage de processus de fils

int main(){
    pid_t pid; 
    int i,j;

    for(i=0;i < NB_PROCESS;i++){
        pid =fork();
        if(pid < 0)
        printf("Erreur de creation du procesus fils\n");
        exit(1);
    else if(pid == 0){
        for(j=0;j < NB_ITERATION;j++){
            printf("processus fils num %d : %d\n",i,j);
        }
        exit(0);
    }
    }
    for(i = 0;i < NB_PROCESS;i++){
        wait(NULL);
    }
    return 0;
}