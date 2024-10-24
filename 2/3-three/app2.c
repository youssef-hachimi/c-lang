#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("1 \n");
    pid_t pid2 = fork();

    if (pid2 == -1) {
        printf("Erreur lors de la création du processus fils");
        exit(1);
    } else if (pid2 == 0) {
        printf("2 \n");
    } else {
        pid_t pid3 = fork();

        if (pid3 == -1) {
            printf("Erreur lors de la création du processus fils");
            exit(1);
        } else if (pid3 == 0) {
            printf("3 \n");
        } else {
            pid_t pid4 = fork();

            if (pid4 == -1) {
                printf("Erreur lors de la création du processus fils");
                exit(1);
            } else if (pid4 == 0) {
                printf("4 \n");
            } else {
                pid_t pid5 = fork();

                if (pid5 == -1) {
                    printf("Erreur lors de la création du processus fils");
                    exit(1);
                } else if (pid5 == 0) {
                    printf("5 \n");
                } else {
                    pid_t pid6 = fork();

                    if (pid6 == -1) {
                        printf("Erreur lors de la création du processus fils");
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
