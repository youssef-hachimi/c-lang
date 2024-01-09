#include <stdio.h>
int main()
{
    char operator;
    int num1, num2, result;
    printf("Enter an operator :(+ - * /)\n");
    scanf("%c", &operator);

    printf("enter the value of a:\n");
    scanf("%d", &num1);

    printf("enter the value of b:\n");
    scanf("%d", &num2);
    // using switch :
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("%d + %d = %d\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("%d - %d = %d\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("%d * %d = %d\n", num1, num2, result);
        break;
    case '/':
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
        break;
    default:
        printf("operator is not valid !\n");
    }
    // using if else condtion :
    // if (operator== '+')
    // {
    //     result = num1 + num2;
    //     printf("%d + %d = %d\n", num1, num2, result);
    // }
    // else if (operator== '-')
    // {
    //     result = num1 - num2;
    //     printf("%d - %d = %d\n", num1, num2, result);
    // }
    // else if (operator== '*')
    // {
    //     result = num1 * num2;
    //     printf("%d * %d = %d\n", num1, num2, result);
    // }
    // else if (operator== '/')
    // {
    //     result = num1 / num2;
    //     printf("%d / %d = %d\n", num1, num2, result);
    // }
    // else
    //     printf("operator is not valid !\n");
}