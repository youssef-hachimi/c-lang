//exercice one TP 1 UN;
#include <stdio.h>
int main(){
    int n,up,uf,i;
    printf("entrer n:");
    scanf("%d",&n);
    up = 1;
    for(i =1;i<=n;i++){
        up = uf;
        if(i%2 == 0 )
        uf =2 * up;
        else
        uf = 2 * up +1;
    }
 printf("Resultat : %d",uf);
}
