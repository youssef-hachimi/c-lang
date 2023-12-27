#include <stdio.h>
int main()
{
  int age;
  char name[30];
  printf("whatis your name?\n");  
  scanf("%s",&name);
  printf("how old are you?\n");
  scanf("%d",&age);
  printf("HI %s you are %d years old!\n",name,age);
}