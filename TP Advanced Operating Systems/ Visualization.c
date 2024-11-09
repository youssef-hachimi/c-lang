#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(){

    int id = fork();
    int n,i;
    if(id == 0){
        n = 1;
    }
    else{
        n = 6;
    }
    for(i=n; i < n + 5 ;i++){
        printf("%d ",i);
        fflush(stdout);
    }
}