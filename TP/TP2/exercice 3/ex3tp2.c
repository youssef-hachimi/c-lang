#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Lecture()
{
    int n;
    printf("entrer un entier:\n");
    scanf("%d", &n);
    return (n);
}
int Fibonacci_non_recursive(int n)
{
    int A, B, C, i;
    if (n == 1 || n == 2)
        A = 1;
    else
    {
        B = 1;
        C = 1;
        for (i = 3; i <= n; i++)
        {
            A = B + C;
            C = B;
            B = A;
        }
    }
    return (A);
}
int Fibonacci_recursive(int n)
{
    if (n == 1 || n == 2)
        return (1);
    else
        return (Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2));
}
void Affiche(int n, int Un)
{
    printf("Pour n=%d, on a Un=%d\n", n, Un);
}
//main function:
int main()
{
    int n, Uv;
    n = Lecture();
    printf("Utilisation de la fonction non recursive:\n");
    Uv = Fibonacci_non_recursive(n);
    Affiche(n, Uv);
    printf("Utilisation de la fonction recursive:\n");
    Uv = Fibonacci_recursive(n);
    Affiche(n, Uv);
    system("pause");
}