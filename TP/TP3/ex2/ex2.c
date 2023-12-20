#include<stdio.h>
#include<stdlib.h>
//global variables 
int n,i,j;
// function of this programme :
void lire(float *A,int d);
void afficher(float *A,int d);
float produit(float *A,float *B,int d);
float *somme(float *A,float *B,int d);
float *Scalaire(float *A,int d,int k);
void distance(float *A,float *B,int d);
// main function :
int main(){
    printf("=============================\n");
    printf("||          Menu           ||\n");
    printf("=============================\n");
    printf("|   1-Lecture               |\n");
    printf("|   2-affichage             |\n");
    printf("|   3-somme                 |\n");
    printf("|   4-produit               |\n");
    printf("|   5-Scalaire              |\n");
    printf("|   6-distance              |\n");
    printf("|   7-Quitter               |\n");
    printf("=============================\n");
    printf("||   Tapez votre choix :    ||\n");
    printf("_____________________________\n");
    scanf("%d",&n);
    void lire();
    void afficher();
    float produit();
    float *somme();
    float *Scalaire();
    void distance();
}
// lecture
void lire(float *A,int d){
    printf("entrer les elements de tableau:\n");
    for(i=0;i<d;i++){
        scanf("%d",&A[i]);
    }
}
void afficher(float *A,int d){
    for(i=0;i<d;i++){
        printf("%d",A[i]);
    }
}
float produit(float *A,float *B,int d){
  int produit;  
  if(i!=0 && j!=0){
    produit = i*j;
  }
  printf("le produit de deux vecteur est :%d",produit);
}
float *somme(float *A,float *B,int d){
  int somme;  
  if(i!=0 && j!=0){
    somme = i+j;
  }
  printf("le produit de deux vecteur est :%d",somme);
}
float *Scalaire(float *A,int d,int k){
int Scalaire;
}
void distance(float *A,float *B,int d){
int distance;
}