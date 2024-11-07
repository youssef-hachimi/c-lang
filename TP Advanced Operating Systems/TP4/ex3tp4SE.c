#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void getalarm(int sig) {
    if (sig == SIGALRM) {
        printf("Trop tard : coffre-fort fermé\n");
        exit(0);
    }
}

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Erreur sur le processus fils");
        exit(0);
    }

    else if (pid == 0) {  // Processus enfant
        sleep(30);
        kill(getppid(), SIGALRM);
        exit(0);
    } else {  // Processus parent
        char code[5];
        signal(SIGALRM, getalarm);

        printf("Entrez le code du coffre-fort : ");
        scanf("%4s", code);

        if (strcmp(code, "2468") == 0) {
            printf("Bravo : coffre-fort ouvert\n");
        } else {
            printf("Code faux : coffre-fort fermé\n");
        }
        wait(NULL);
    }

    return 0;
}