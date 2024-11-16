#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int p1[2], p2[2];  // p1 pour père -> fils, p2 pour fils -> père
    pid_t pid;
    
    // Création des pipes
    pipe(p1);
    pipe(p2);
    if (pipe(p1) == -1 || pipe(p2) == -1) {
        perror("Erreur lors de la création des pipes");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("Erreur lors de la création du processus fils");
        exit(1);
    } else if (pid == 0) {
        // Code du processus fils
        close(p1[1]);  // Ferme l'écriture de p1 (lecture seule)
        close(p2[0]);  // Ferme la lecture de p2 (écriture seule)
        
        int received_numbers[5];
        int doubled_numbers[5];
        
        // Lecture des 5 entiers envoyés par le père
        read(p1[0], received_numbers, sizeof(received_numbers));
        
        // Double les entiers et les stocke dans doubled_numbers
        for (int i = 0; i < 5; i++) {
            doubled_numbers[i] = received_numbers[i] * 2;
        }
        
        // Envoi des entiers doublés au père
        write(p2[1], doubled_numbers, sizeof(doubled_numbers));
        
        close(p1[0]);
        close(p2[1]);
    } else {
        // Code du processus père
        close(p1[0]);  // Ferme la lecture de p1 (écriture seule)
        close(p2[1]);  // Ferme l'écriture de p2 (lecture seule)
        
        int numbers_to_send[5] = {1, 2, 3, 4, 5};
        int received_doubles[5];
        
        // Envoi des 5 entiers au fils
        write(p1[1], numbers_to_send, sizeof(numbers_to_send));
        
        // Lecture des entiers doublés envoyés par le fils
        read(p2[0], received_doubles, sizeof(received_doubles));
        
        // Affichage des entiers doublés
        printf("Les entiers doublés sont : ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", received_doubles[i]);
        }
        printf("\n");
        
        close(p1[1]);
        close(p2[0]);
        
        // Attend la fin du processus fils
        wait(NULL);
    }

    return 0;
}
