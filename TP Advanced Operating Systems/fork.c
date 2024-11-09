#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    
    int ID = fork();

    if(ID == 0){
        printf("hello world from child proceses ! \n");
    }
    else if(ID == -1){
        printf("Erreur !\n");
    }
    else{
        printf("hello world from parent processes !\n");
    }

    // if(ID != 0){
    //     fork();
    // }
    // printf("hello proce\n");

}