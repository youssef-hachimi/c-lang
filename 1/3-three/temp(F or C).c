#include<stdio.h>
int main()
{
    char unit;
    float temp;
    printf("the temp in (F) or (C) ? :\n");
    scanf("%c",&unit);

    if(unit == 'C'){
        printf("enter the temp in Celsius\n");
        scanf("%f",&temp);
        temp = (temp*9/5 ) +32;
        printf("the temp in farenheit is %.2f\n",temp);
    }
    else if(unit == 'F'){
        printf("enter the temp in farenheit\n");
        scanf("%f",&temp);
        temp = ((temp - 32 )*5)/9;
        printf("the temp in Celsius is %.2f\n",temp);   
    }
    else printf("try again!");

}