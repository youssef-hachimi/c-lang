#include <stdio.h>
void hello(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("hello\n");
    }
}
void sum(int num1,int num2){
    int result = num1 + num2;
    printf(": %d\n",result);
}
int main()
{
    int n,a,b;
    printf("entrer la valeur de n\n");
    scanf("%d",&n);
    hello(n);
    printf("entrer la valeur de a\n");
    scanf("%d",&a);
    printf("entrer la valeur de b\n");
    scanf("%d",&b);
    sum(a,b);
}

