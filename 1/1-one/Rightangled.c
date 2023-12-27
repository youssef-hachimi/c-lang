#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    printf("Enter the value of a :\n");
    scanf("%d", &a);
    printf("Enter the value of b :\n");
    scanf("%d", &b);
    c = sqrt(pow(a, 2) + pow(b, 2));
    printf("the Right angled triangle is :%d\n", c);
}