#include <stdio.h>
void card(char x[], int y)
{
    printf("Hi my name is %s\n",x);
    printf("I am %d years old\n",y);
}
int main()
{
    char name[30];
    int age;
    printf("Enter your name:\n");
    scanf("%s",&name);
    printf("how old are you?\n");
    scanf("%d",&age);    
    card(name, age);
}