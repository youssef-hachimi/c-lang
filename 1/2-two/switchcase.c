#include <stdio.h>
int main()
{
    char grade;
    printf("Enter the letter of your grade :\n");
    scanf("%c", &grade);
    switch (grade)
    {
    case 'A':printf("Perfect!\n");
        break;
    case 'B':printf("you did good!\n");
        break;
    case 'C':printf("you did okay!\n");
        break;
    case 'D':printf("At least it's not an F!\n");
        break;
    case 'F':printf("You FAILED!\n");
        break;
    default: printf("try again!\n");
    }
}