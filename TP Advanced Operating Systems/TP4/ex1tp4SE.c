#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void getsig(int sig) {
    if (sig == SIGUSR1) {
        printf("Enfant : Reçu SIGUSR1 du parent\n");
    }
}

int main() {
    int fd[2];
    pid_t pid;
    char *messages[] = {"Message 1", "Message 2", "Message 3"};
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("Erreur pipe");
        return -1;
    }

    pid = fork();

    if (pid  == -1) {
        perror("Erreur sur le processus de fils");
        exit(0);
    } else if (pid == 0) {  // Processus enfant
        close(fd[1]);   // Fermer l'écriture dans le tube
        signal(SIGUSR1, getsig);

        for (int i = 0; i < 3; i++) {
            read(fd[0], buffer, sizeof(buffer));
            printf("Enfant : Reçu - %s\n", buffer);
        }
        // pause();  // Attendre le signal
        close(fd[0]);
    } 
    else {  // Processus parent
        close(fd[0]);   // Fermer la lecture dans le tube

        for (int i = 0; i < 3; ++i) {
            write(fd[1], messages[i], strlen(messages[i]) + 1);
            printf("Parent : Envoyé - %s\n", messages[i]);
        }
        close(fd[1]);
        kill(pid, SIGUSR1);
        wait(NULL);  // Attendre la fin du processus enfant
    }

    return 0;
}
