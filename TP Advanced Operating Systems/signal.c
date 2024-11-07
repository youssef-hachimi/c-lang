#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    pid_t pid = fork();
    if(pid == -1){
        return 1;
    }
    else if(pid == 0){
        while(1){
            printf("some text goes here \n");
            sleep(5);
        }
    }
    else{
        wait(NULL);
    }
    return 0;
}