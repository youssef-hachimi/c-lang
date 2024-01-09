//richestpepole rank
#include <stdio.h>
void richestpepole(int,char[],float);
int main()
{
richestpepole(1,"Bill Gates",86);
richestpepole(2,"Warren Buffet",75,4);
richestpepole(3,"Jeff Bezos",70);
richestpepole(4,"me",0);
return 0;
}
void richestpepole(int rank,char name[],float networth){
    printf("#%d\t",rank);
    printf("%s\t",name);
    printf("%.lf Billion Dollars\n",networth);
    return;
}