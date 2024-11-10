#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// recpr pour le signal SIGTERM
void recp_sigterm(int sig) {
    printf("Signal SIGTERM reçu\n");
    exit(0);
}

int main() {
    pid_t child1, child2;

    // Création du premier processus enfant
    child1 = fork();
    if (child1 == -1) {
        perror("Erreur lors de la création du premier processus enfant");
        exit(1);
    } else if (child1 == 0) {
        // Processus enfant 1
        signal(SIGTERM, recp_sigterm);
        while (1) {
            // Boucle infinie pour attendre le signal
            pause();
        }
    }

    // Création du deuxième processus enfant
    child2 = fork();
    if (child2 == -1) {
        perror("Erreur lors de la création du deuxième processus enfant");
        exit(1);
    } else if (child2 == 0) {
        // Processus enfant 2
        signal(SIGTERM, recp_sigterm);
        while (1) {
            // Boucle infinie pour attendre le signal
            pause();
        }
    }

    // Processus parent attend 5 secondes
    sleep(5);

    // Envoi du signal SIGTERM aux processus enfants
    kill(child1, SIGTERM);
    kill(child2, SIGTERM);

    // Attente de la fin des deux processus enfants
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);

    printf("Les deux processus enfants se sont terminés. Fin du processus parent.\n");

    return 0;
}
