#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// signaux recepteur pour processus de parent
void recp_signal(int sig) {
    printf("le processus parent recvoie singaux SIGUSR1 de processus fils \n ");
}

int main() {
    pid_t pid1,pid2;
    
    // Register le signal recpteur pour SIGUSR1
    signal(SIGUSR1, recp_signal);
    
    // creation de premier processus fils
    pid1 = fork();
    if (pid1 == 0) {
        // sur le premier processus fils
        printf("le fils 1 avec PID %d envoyer SIGUSR1 a parent. \n ",getpid());
        kill(getppid(), SIGUSR1);  //  Envoyer le signaux a parent
        exit(0);  // Terminer le fils 1
    }

    // creation de dexieme processus fils
    pid2 = fork();
    if (pid2 == 0) {
        // sur le dexieme processus fils
        printf("le fils 2 avec PID %d envoyer SIGUSR1 a parent.\n", getpid());
        kill(getppid(), SIGUSR1);  //Envoyer le signaux a parent
        exit(0);  // Terminer le fils 2
    }

    // Parent process waits for both children to terminate
    // parent attender les deux fils pour fini.
    wait(NULL);
    wait(NULL); 

    printf("Processus parent: les deux fils est terminer !.\n");

     return 0;
}