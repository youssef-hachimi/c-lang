// Exercice 2 :
#include <stdio.h>
#include <string.h>
#define max 30
void lecture(char chaine[max]);
int verbe_er(char chaine[max]);
void conjuguer(char chaine[max]);
main()
{
    char verbe[20];
    lecture(verbe);
    if (verbe_er(verbe) == 0)
        printf("Erreur\n");
    else
        conjuguer(verbe);
}

void lecture(char chaine[max])
{
    printf("donnez un verbe régulier: \n");
    gets(chaine);
}
int verbe_er(char chaine[max])
{
    int lg, res = 0;
    lg = strlen(chaine);
    if (chaine[lg-2] == 'e' && chaine[lg-1] == 'r')
        res = 1;
    return (res);
}
void conjuguer(char chaine[max])
{
    char *term[6] = {"e", "es", "e", "ons", "ez", "ent"};
    char *sujet[6] = {"je ", "tu ", "il ", "nous ", "vous ", "ils "};
    char copie[max];
    int lg, i;
    lg = strlen(chaine);
    chaine[lg-2] = '\0';
    for (i = 0; i < 6; i++)
    {
        strcpy(copie, sujet[i]);
        strcat(copie, chaine);
        strcat(copie, term[i]);
        printf(" %s \n", copie);
    }
}