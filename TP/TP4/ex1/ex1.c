// Exercice 1 :
#include <stdio.h>
#include <stdlib.h>
// les fonctions dons ce programme
int **allouer(int L, int C);
void liberation(int **A, int L, int C);
void lecture(int **A, int L, int C);
void affichage(int **A, int L, int C);
int **produit(int **A, int **B, int L, int LC, int C);
// main fonction
int main()
{
     int **M1, **M2, **M3;
     int Lig, LC, Col;
     printf("Entrer les valeurs de Lig, LC et Col: \n");
     scanf("%d%d%d", &Lig, &LC, &Col);
     M1 = allouer(Lig, LC);
     M2 = allouer(LC, Col);
     if (M1 == NULL || M2 == NULL)
     {
          printf("Erreur de réervation\n");
          exit(0);
     }
     printf("=== Matrice M1===\n");
     lecture(M1, Lig, LC);
     affichage(M1, Lig, LC);
     printf("=== Matrice M2===\n");
     lecture(M2, LC, Col);
     affichage(M2, LC, Col);

     printf("=== Matrice M3===\n");
     M3 = produit(M1, M2, Lig, LC, Col);
     affichage(M3, Lig, Col);
     liberation(M1, Lig, LC);
     liberation(M2, LC, Col);
}
int **allouer(int L, int C)
{
     int i;
     int **A;
     A = (int **)malloc(L * sizeof(int *));
     if (A == NULL)
     {
          printf("Erreur\n");
          exit(0);
     }
     for (i = 0; i < L; i++)
     {
          A[i] = (int *)malloc(C * sizeof(int));
          if (A[i] == NULL)
          {
               printf("Erreur\n");
               exit(0);
          }
     }
     return A;
}
void liberation(int **A, int L, int C)
{
     int i;
     for (i = 0; i < L; i++)
          free(A[i]);
     free(A);
     printf("Libération effctuée\n");
}
void lecture(int **A, int L, int C)
{
     int i, j;
     for (i = 0; i < L; i++)
     {
          for (j = 0; j < C; j++)
          {
               printf("Entrer élément (%d,%d): \n", i, j);
               scanf("%d", &A[i][j]);
          }
     }
}
void affichage(int **A, int L, int C)
{
     int i, j;
     for (i = 0; i < L; i++)
     {
          for (j = 0; j < C; j++)
          {
               printf(" %d ", A[i][j]);
          }
          printf("\n");
     }
}
int **produit(int **A, int **B, int L, int LC, int C)
{
     int i, j, k, p;
     int **S;
     S = allouer(L, C);
     if (S == NULL)
     {
          printf("Erreur de réservation\n");
          exit(0);
     }
     for (i = 0; i < L; i++)
     {
          for (j = 0; j < C; j++)
          {
               p = 0;
               for (k = 0; k < LC; k++)
               {
                    p = p + A[i][k] * B[k][j];
               }
               S[i][j] = p;
          }
     }
     return (S);
}
