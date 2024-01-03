// Exercice 1 :
#include <stdio.h>
#include <string.h>
#define max 50
// data structuers
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
int nbv = 0; // Number of students valid semestre

// prototype function:
void lecture(Etudiant ESTBM[max],int N);
void affichage(Etudiant ESTBM[max],int N);
int valide_semestre(float NT[24],int id_debut,int id_fin);
int valide_tous_semestres(Etudiant ETD);
Etudiant* etud_valide_semestres(Etudiant ESTBM,int n);
Etudiant* etud_ordre_merite(Etudiant ESTBM,int n);
void mention(Etud A,int n);
// lecture function:
void lecture(Etudiant ESTBM[max], int N)
{
    int i, j;
    printf("Saisir les etudiants: \n");
    for (i = 0; i < N; i++)
    {
        printf("Etudiant n°: %d \n", (i + 1));
        printf("Entrer NOM: \n");
        scanf("%s", &ESTBM[i].nom);
        printf("Entrer PRENOM: \n");
        scanf("%s", &ESTBM[i].prenom);
        printf("Entrer CNE: \n");
        scanf("%d", &ESTBM[i].cne);
        printf("Entrer DATE DE NAISSANCE: \n");

        scanf("%d%d%d", &ESTBM[i].naissance.jour, &ESTBM[i].naissance.mois, &ESTBM[i].naissance.annee);
        for (j = 0; j <24; j++)
        {
            printf("Entrer la note n°: %d \n", (j + 1));
            scanf("%f", &ESTBM[i].notes[j]);
        }
    }
}
void affichage(Etudiant ESTBM[max], int N)
{
    int i, j;
    printf("Afficher les etudiants: \n");
    for (i = 0; i < N; i++)
    {
        printf("Etudiant n°: %d \n", (i + 1));
        printf("NOM: %s \n", ESTBM[i].nom);
        printf("PRENOM: %s \n", ESTBM[i].prenom);
        printf("CNE: %d \n", ESTBM[i].cne);
        printf("DATE DE NAISSANCE: %d-%d-%d\n", ESTBM[i].naissance.jour, ESTBM[i].naissance.mois, ESTBM[i].naissance.annee);
        for (j = 0; j < 24; j++)
        {
            printf("NOTE n°%d  est: %f \n", (j + 1), ESTBM[i].notes[j]);
        }
    }
}
int valideSemestre(float NT[24], int iDdebut, int iDfin)
{
    int i, k = 0, res = 0;
    float s = 0;
    for (i = iDdebut; i <= iDfin; i++)
    {
        s = s + NT[i];
        if (NT[i] >= 7)
            k++;
    }
    if (s / 6 >= 12 && k == 6)
        res = 1;
    return (res);
}
int valideTousSemestres(Etudiant ETD)
{
    int deb, fin, k = 0, i, res = 0;
    for (i = 0; i < 4; i++)
    {
        deb = 6 * i;
        fin = deb + 5;
        k = k + valideSemestre(ETD.notes, deb, fin);
    }
    if (k == 4)
        res = 1;
    return (res);
}
Etudiant *etudValideSemestres(Etudiant ESTBM[max], int n)
{
    Etudiant T[max];
    int i, j = 0;
    for (i = 0; i < n; i++)
    {
        if (valideTousSemestres(ESTBM[i]) == 1)
        {
            T[j] = ESTBM[i];
            j++;
        }
    }
    nbv = j;
    return (T);
}
float moyenne(float NT[24])
{
    float s = 0;
    int i;
    for (i = 0; i < 24; i++)
    {
        s = s + NT[i];
    }
    return (s / 24);
}
Etudiant *etudOrdreMerite(Etudiant ESTBM[max], int n)
{
    Etudiant *V, et;
    float moyennes[max], y;
    int i, j, idmax;
    V = etudValideSemestres(ESTBM, n);
    for (i = 0; i < nbv; i++)
    {
        moyennes[i] = moyenne(V[i].notes);
    }
    for (i = 0; i < nbv - 1; i++)
    {
        idmax = i;
        for (j = i + 1; j < nbv; j++)
        {
            if (moyennes[j] > moyennes[idmax])
                idmax = j;
        }
        if (max != i)
        {
            y = moyennes[i];
            moyennes[i] = moyennes[idmax];
            moyennes[idmax] = y;
            et = V[i];
            V[i] = V[idmax];
            V[idmax] = et;
        }
    }
    return (V);
}
char *appreciation(float moy)
{
    char texte[20];
    if (moy >= 12 && moy < 14)
        strcpy(texte, "Assez bien");
    if (moy >= 14 && moy < 16)
        strcpy(texte, "Bien");
    if (moy >= 16)
        strcpy(texte, "Tres bien");
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
main()
{
    int NB;
    Etud EST;
    printf("Entrer le nombre des etudiants à saisir:");
    scanf("%d", &NB);
    lecture(EST, NB);
    affichage(EST, NB);
    mention(EST, NB);
}