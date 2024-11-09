#include <stdio.h> // input / output
#include <sys/types.h> // pour le type pid_t
#include <sys/wait.h>// pour fonction wait
#include <stdlib.h>// pour fonction exit
#include <unistd.h> // pour gestion des processus 
int main(){
	// declaration du variable pid
   pid_t pid = fork();
  // operation de fils
  if(pid == 0){
	printf("est l'operation de fils \n");
	int i;
    	for(i = 1 ;i<= 10 ;i++){
	 printf("%d\n",i);
         }
   }
  // operation de parent
  else if(pid > 0){
	wait(NULL);
        printf("est l'operation de parent \n");
        int i;
        for(i=11;i<=20 ;i++){
         printf("%d\n",i);
         }
   }
   // dans le cas de erreur
   else{
	printf("Erreur \n");
       }


return 0;


}
