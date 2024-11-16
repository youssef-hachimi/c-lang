#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

int pipefd[2];

void handle_sigusr1(int sig) {
    printf("Signal reçu : SIGUSR1\n");
}

void handle_sigusr2(int sig) {
    printf("Signal reçu : SIGUSR2\n");
}

void handle_sigterm(int sig) {
    printf("Signal reçu : SIGTERM\n");
    exit(0);
}

int main() {
    pid_t pid;
    
    // Création du tube
    if (pipe(pipefd) == -1) {
        perror("Erreur lors de la création du tube");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(1);
    } else if (pid == 0) {
        // Code du processus client (fils)
        close(pipefd[0]);  // Ferme la lecture du tube (écriture seule)

        // Envoi des signaux au serveur
        kill(getppid(), SIGUSR1);
        sleep(1);
        kill(getppid(), SIGUSR2);
        sleep(1);
        kill(getppid(), SIGTERM);

        // Envoi du message dans le tube
        char message[] = "Message reçu";
        write(pipefd[1], message, strlen(message) + 1);
        
        close(pipefd[1]);
        exit(0);
    } else {
        // Code du processus serveur (père)
        close(pipefd[1]);  // Ferme l'écriture du tube (lecture seule)

        // Gestion des signaux
        signal(SIGUSR1, handle_sigusr1);
        signal(SIGUSR2, handle_sigusr2);
        signal(SIGTERM, handle_sigterm);

        // Attente et lecture du message envoyé par le client
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Message du client : %s\n", buffer);
        
        close(pipefd[0]);
        
        // Attend la fin du processus client
        wait(NULL);
    }

    return 0;
}
