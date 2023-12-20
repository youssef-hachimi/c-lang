#include <stdio.h>

int iHeure, iMinute, iSeconde;

void affiche_heure();
void saisir_heure(int iH, int iM, int iS);
void tick();

int main() {
  int H, M, S;
  saisir_heure(H, M, S);
  affiche_heure();
  tick();
}

void affiche_heure() {
  printf("Il est %d heure(s) %d minute(s) %d Seconde(s)\n", iHeure, iMinute, iSeconde);
}

void saisir_heure(int iH, int iM, int iS) {
  printf("Entrer le temps de heures : \n");
  scanf("%d", &iH);
  printf("Entrer le temps de minutes : \n");
  scanf("%d", &iM);
  printf("Entrer le temps de secondes : \n");
  scanf("%d", &iS);
  iHeure = iH;
  iMinute = iM;
  iSeconde = iS;
}

void tick() {
  int total;
  total = iHeure * 3600 + iMinute * 60 + iSeconde;
  total += 1;
  iHeure = total / 3600;
  iMinute = (total % 3600) / 60;
  iSeconde = total % 60;
  affiche_heure();
}



/////////////////////////////////////////////////////////////////////////
/*
#include <stdio.h>
int iHeure,iMinute,iSeconde;
void affiche_heure();
void saisir_heure(int iH, int iM, int iS);
void tick();
int main(){
  int H,M,S;
  saisir_heure(H,M,S);
  affiche_heure(iHeure,iMinute,iSeconde);
  tick(iHeure,iMinute,iSeconde);
}
void affiche_heure(){
  printf("Il est %d heure(s) %d minute(s)%d Seconde(s)\n",iHeure,iMinute,iSeconde);
}
void saisir_heure(int iH,int iM,int iS){
  printf("Entrer le temps de heurs : \n");
  scanf("%d",&iH);
  printf("Entrer le temps de minutes : \n");
  scanf("%d",&iM);
  printf("Entrer le temps de secondes : \n");
  scanf("%d",&iS);
  iHeure = iH;
  iMinute = iM;
  iSeconde = iS;
}
void tick(){
  int total;
  total = iHeure*3600+iMinute*60+iSeconde;
  total += 1;
  iHeure = total/3600;
  iMinute = (total-(iHeure*3600)/60);
  iSeconde = (total-(iHeure*3600)-(iMinute*60));
  affiche_heure();
}
*/
