#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    char nom[20];
    char prenom[20];
    int cne;
    Date naissance;
    float notes[24];
} Etudiant;

typedef Etudiant Etud[max];

void lecture(Etud A, int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        printf("Etudiant %d:\n", i + 1);
        printf("Nom: ");
        scanf("%s", A[i].nom);
        printf("Prénom: ");
        scanf("%s", A[i].prenom);
        printf("CNE: ");
        scanf("%d", &A[i].cne);
        printf("Date de naissance (jj/mm/aaaa): ");
        scanf("%d/%d/%d", &A[i].naissance.jour, &A[i].naissance.mois, &A[i].naissance.annee);
        for (j = 0; j < 24; j++)
        {
            printf("Note %d: ", j + 1);
            scanf("%f", &A[i].notes[j]);
        }
        printf("\n");
    }
}

void affichage(Etud A, int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        printf("Etudiant %d:\n", i + 1);
        printf("Nom: %s\n", A[i].nom);
        printf("Prénom: %s\n", A[i].prenom);
        printf("CNE: %d\n", A[i].cne);
        printf("Date de naissance: %d/%d/%d\n", A[i].naissance.jour, A[i].naissance.mois, A[i].naissance.annee);
        printf("Notes:\n");
        for (j = 0; j < 24; j++)
        {
            printf("Note %d: %.2f\n", j + 1, A[i].notes[j]);
        }
        printf("\n");
    }
}

int valide_semestre(float NT[24], int id_debut, int id_fin)
{
    int i;
    float somme = 0;
    for (i = id_debut; i <= id_fin; i++)
    {
        if (NT[i] < 7)
        {
            return 0; // Note inférieure à 7, semestre non validé
        }
        somme += NT[i];
    }
    float moyenne = somme / (id_fin - id_debut + 1);
    if (moyenne >= 10)
    {
        return 1; // Semestre validé
    }
    else
    {
        return 0; // Moyenne inférieure à 10, semestre non validé
    }
}

int valide_tous_semestres(Etudiant ETD)
{
    int i;
    for (i = 0; i < 4; i++)
    { // Supposons que l'étudiant a 4 semestres
        int id_debut = i * 6;
        int id_fin = (i + 1) * 6 - 1;
        if (!valide_semestre(ETD.notes, id_debut, id_fin))
        {
            return 0; // Un semestre non validé, donc l'étudiant n'a pas validé tous les semestres
        }
    }
    return 1; // Tous les semestres validés
}

Etudiant *etud_valide_semestres(Etud A, int n)
{
    int i, j;
    int count = 0;
    for (i = 0; i < n; i++)
    {
        if (valide_tous_semestres(A[i]))
        {
            count++;
        }
    }
    Etudiant *etud_valides = malloc(count * sizeof(Etudiant));
    if (etud_valides == NULL)
    {
        printf("Erreur d'allocation mémoire.\n");
        return NULL;
    }
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (valide_tous_semestres(A[i]))
        {
            etud_valides[j] = A[i];
            j++;
        }
    }
    return etud_valides;
}
void mention(Etud A, int n)
{
    Etudiant *B;
    int i;
    float m;
    B = etudOrdreMerite(A, n);
    printf("Liste des etudiants par ordre de merite: \n");
    for (i = 0; i < nbv; i++)
    {
        m = moyenne(B[i].notes);
        printf("--> CNE: %d NOM: %s PRENOM: %s MOYENNE: %f MENTION: %s\n", B[i].cne, B[i].nom, B[i].prenom, m, appreciation(m));
    }
}
int main()
{
    int NB;
    Etud EST;
    printf("Entrer le nombre des etudiants à saisir:");
    scanf("%d", &NB);
    lecture(EST, NB);
    affichage(EST, NB);
    mention(EST, NB);
}




// #include <stdio.h>
// #include<string.h>
// #define max 50
// typedef struct
// {
//     int jour;
//     int mois;
//     int annee;
// } Date;

// typedef struct
// {
//     char nom[20];
//     char prenom[20];
//     int cne;
//     Date naissance;
//     float notes[24];
// } Etudiant;
// typedef Etudiant Etud[max];
// int nbv = 0; // Nombre des étudiants qui ont validé tous les semestres
// void lecture(Etud A, int N)
// {
//     int i, j;
//     printf("Saisir les etudiants: \n");
//     for (i = 0; i < N; i++)
//     {
//         printf("Etudiant n°: %d \n", (i + 1));
//         printf("Entrer NOM: \n");
//         scanf("%s", &A[i].nom);
//         printf("Entrer PRENOM: \n");
//         scanf("%s", &A[i].prenom);
//         printf("Entrer CNE: \n");
//         scanf("%d", &A[i].cne);
//         printf("Entrer DATE DE NAISSANCE: \n");

//         scanf("%d%d%d", &A[i].naissance.jour, &A[i].naissance.mois, &A[i].naissance.annee);
//         for (j = 0; j < 24; j++)
//         {
//             printf("Entrer la note n°: %d \n", (j + 1));
//             scanf("%f", &A[i].notes[j]);
//         }
//     }
// }
// void affichage(Etud A, int N)
// {
//     int i, j;
//     printf("Afficher les etudiants: \n");
//     for (i = 0; i < N; i++)
//     {
//         printf("NOM: %s \n", A[i].nom);
//         printf("PRENOM: %s \n", A[i].prenom);
//         printf("CNE: %d \n", A[i].cne);
//         printf("DATE DE NAISSANCE: %d-%d-%d\n", A[i].naissance.jour, A[i].naissance.mois, A[i].naissance.annee);
//         for (j = 0; j < 24; j++)
//         {
//             printf("NOTE n°%d est: %f \n", (j + 1), A[i].notes[j]);
//         }
//     }
// }
// int valideSemestre(float NT[24], int iDdebut, int iDfin)
// {
//     int i, k = 0, res = 0;
//     float s = 0;
//     for (i = iDdebut; i <= iDfin; i++)
//     {
//         s = s + NT[i];
//         if (NT[i] >= 7)
//             k++;
//     }
//     if (s / 6 >= 10 && k == 6)
//         res = 1;
//     return (res);
// }
// int valideTousSemestres(Etudiant ETD)
// {
//     int deb, fin, k = 0, i, res = 0;
//     for (i = 0; i < 4; i++)
//     {
//         deb = 6 * i;
//         fin = deb + 5;
//         k = k + valideSemestre(ETD.notes, deb, fin);
//     }
//     if (k == 4)
//         res = 1;
//     return (res);
// }
// Etudiant *etudValideSemestres(Etud A, int n)
// {
//     Etudiant T[max];
//     int i, j = 0;
//     for (i = 0; i < n; i++)
//     {
//         if (valideTousSemestres(A[i]) == 1)
//         {
//             T[j] = A[i];
//             j++;
//         }
//     }
//     nbv = j;
//     return (T);
// }
// float moyenne(float NT[24])
// {
//     float s = 0;
//     int i;
//     for (i = 0; i < 24; i++)
//     {
//         s = s + NT[i];
//     }
//     return (s / 24);
// }
// Etudiant *etudOrdreMerite(Etud A, int n)
// {
//     Etudiant *V, et;
//     float moyennes[max], y;
//     int i, j, idmax;
//     V = etudValideSemestres(A, n);
//     for (i = 0; i < nbv; i++)
//     {
//         moyennes[i] = moyenne(V[i].notes);
//     }
//     for (i = 0; i < nbv - 1; i++)
//     {
//         idmax = i;
//         for (j = i + 1; j < nbv; j++)
//         {
//             if (moyennes[j] > moyennes[idmax])
//                 idmax = j;
//         }
//         if (max != i)
//         {
//             y = moyennes[i];
//             moyennes[i] = moyennes[idmax];
//             moyennes[idmax] = y;
//             et = V[i];
//             V[i] = V[idmax];
//             V[idmax] = et;
//         }
//     }
//     return (V);
// }
// char *appreciation(float moy)
// {
//     char texte[20];
//     if (moy >= 10 && moy < 12)
//         strcpy(texte, "Passable");
//     if (moy >= 12 && moy < 14)
//         strcpy(texte, "Assez bien");
//     if (moy >= 14 && moy < 16)
//         strcpy(texte, "Bien");
//     if (moy >= 16)
//         strcpy(texte, "Tres bien");
// }
// void mention(Etud A, int n)
// {
//     Etudiant *B;
//     int i;
//     float m;
//     B = etudOrdreMerite(A, n);
//     printf("Liste des etudiants par ordre de merite: \n");
//     for (i = 0; i < nbv; i++)
//     {
//         m = moyenne(B[i].notes);
//         printf("--> CNE: %d NOM: %s PRENOM: %s MOYENNE: %f MENTION: %s\n", B[i].cne, B[i].nom, B[i].prenom, m, appreciation(m));
//     }
// }
// int main()
// {
//     int NB;
//     Etud EST;
//     printf("Entrer le nombre des etudiants à saisir:");
//     scanf("%d", &NB);
//     lecture(EST, NB);
//     affichage(EST, NB);
//     mention(EST, NB);
// }
