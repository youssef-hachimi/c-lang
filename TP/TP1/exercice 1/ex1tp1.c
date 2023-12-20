// exercice 1 tp 1
#include <stdio.h>
#include <math.h>
int main(){
    int ib,s = 0,i = 0,res,nib ;
    printf("entrer une formation binaire :\n");
    scanf("%d",&ib);
    nib = ib;
    while (ib!= 0)
    { 
    res = ib % 10;
    s = s + res*pow(2,i);
    i = i++; // i+1
    ib = ib/10;
    }
    printf("converstion de %d en decimal est: %d",nib,s);
}

/* ib s i r inb
scan ilog
while () !-0
r = ib
{
    s = 0
    r= ib %10
    s = s + r pow (2.i)
i = 0
s = 0
i = i++
nib = ib /10


 whi (ib != 10 {

 }
    int res de ib %10
    s = s+ res

        res = ib % 10;
    s = s + res*pow(2,i);

    printf();
    /* code */
