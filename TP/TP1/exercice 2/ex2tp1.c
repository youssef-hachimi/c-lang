#include <stdio.h>
#include <math.h>
 main(){
    int CP,N,AM,R,S;
    CP = 0;N =101;
    printf("les nombres d\'amstrong sont:\n");
    while(CP<4){
        AM = N;
        S = 0;
        while(AM != 0){
           R = AM%10;
           S = S + pow(R,3);
           AM = AM/10;
        }
            if(S == N){
            printf("N\'%d est:%d\n",CP+1,N);
            CP = CP+1; // cp++
        }
        N = N+1;
    }
}
