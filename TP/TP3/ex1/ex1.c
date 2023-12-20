#include <stdio.h>
#include <stdlib.h>
// functions used in this programme.
void lire(int A[],int d);
void afficher(int A[],int d);
void trier(int A[],int d);
int rechercher(int A[],int d,int elt);
// variables global.
int i;
// main function.
void main(){
void lire();
void afficher();
void trier();
}
// function "lire".
void lire(int A[],int d){
    printf("entrer la valeur de d:\n");
    scanf("%d",&d);
    printf("entrer les elements de tableau:\n");
    for(i=0;i<d;i++){
        scanf("%d",&A[i]);
    }
}
// function "affhicher".
void afficher(int A[],int d){
        for(i=0;i<d;i++){
        printf("%d",A[i]);
    }
}
//function "trier"(order croissant).
void trier(int A[],int d){

}
// function "rechercher" (0/1).
int rechercher(int A[],int d,int elt){
    int start,finsh,stop;
}
