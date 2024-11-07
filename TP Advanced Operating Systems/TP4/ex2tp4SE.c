#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pAB[2], pBC[2], pCD[2];
    pid_t pidA, pidB, pidC, pidD;
    int list[10];

    if (pipe(pAB) == -1 || pipe(pBC) == -1 || pipe(pCD) == -1) {
        perror("Erreur pipe");
        exit(1);
    }

    pidA = fork();
    if (pidA == 0) {  // Processus A
        close(pAB[0]);  // Fermer la lecture
        for (int i = 0; i < 10; ++i) {
            list[i] = rand() % 100;
        }
        write(pAB[1], list, sizeof(list));
        close(pAB[1]);
        exit(0);
    }

    pidB = fork();
    if (pidB == 0) {  // Processus B
        int received[10];
        close(pAB[1]);  // Fermer l'écriture
        close(pBC[0]);  // Fermer la lecture

        read(pAB[0], received, sizeof(received));
        close(pAB[0]);
        // Transférer les données au processus C
        write(pBC[1], received, sizeof(received));
        close(pBC[1]);
        exit(0);
    }

    pidC = fork();
    if (pidC == 0) {  // Processus C
        int received[10];
        int sum = 0, product = 1;
        close(pBC[1]);  // Fermer l'écriture
        close(pCD[0]);  // Fermer la lecture

        read(pBC[0], received, sizeof(received));
        close(pBC[0]);
        for (int i = 0; i < 10; i++) {
            sum += received[i];
            product *= received[i];
        }
        int results[2] = {sum, product};
        write(pCD[1], results, sizeof(results));
        close(pCD[1]);
        exit(0);
    }

    pidD = fork();
    if (pidD == 0) {  // Processus D
        int results[2];
        close(pCD[1]);  // Fermer l'écriture

        read(pCD[0], results, sizeof(results));
        close(pCD[0]);
        printf("Processus D : Somme = %d, Produit = %d\n", results[0], results[1]);
        exit(0);
    }

    // Processus parent
    close(pAB[0]);
    close(pAB[1]);
    close(pBC[0]);
    close(pBC[1]);
    close(pCD[0]);
    close(pCD[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}