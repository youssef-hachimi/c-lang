#include <stdio.h> // pour les fonctions input output come printf ,scanf .
#include <stdlib.h> // Inclure la bibliothèque standard pour des fonctions comme malloc .
#include <unistd.h>
#include <sys/types.h> // les définitions pour les types de données utilisés dans gestion des processus.
int main() {
    printf("1 \n");
    pid_t pid2 = fork();

    if (pid2 == -1) {
        printf("Erreur de création du processus fils");
        exit(1);
    } else if (pid2 == 0) {
        printf("2 \n");
    } else {
        pid_t pid3 = fork();

        if (pid3 == -1) {
            printf("Erreur  de création du processus fils");
            exit(1);
        } else if (pid3 == 0) {
            printf("3 \n");
        } else {
            pid_t pid4 = fork();

            if (pid4 == -1) {
                printf("Erreur de création du processus fils");
                exit(1);
            } else if (pid4 == 0) {
                printf("4 \n");
            } else {
                pid_t pid5 = fork();

                if (pid5 == -1) {
                    printf("Erreur de création du processus fils");
                    exit(1);
                } else if (pid5 == 0) {
                    printf("5 \n");
                } else {
                    pid_t pid6 = fork();

                    if (pid6 == -1) {
                        printf("Erreur  de création du processus fils");
                        exit(1);
                    } else if (pid6 == 0) {
                        printf("6 \n");
                    }
                }
            }
        }
    }

    return 0;
}
