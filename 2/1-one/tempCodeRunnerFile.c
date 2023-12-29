#include <stdio.h>
#include <stdlib.h>
// prototype
int somme(int a, int b);
int persent(int a, int b);
int division(int a, int b);
int multi(int a, int b);

// main function
int main()
{
    int x, y;
    char op;
    printf("enter the operator do you want:\n");
    scanf("%c", &op);
    printf("enter the value of x and y:\n");
    scanf("%d%d", &x, &y);
    if(op == '+'){