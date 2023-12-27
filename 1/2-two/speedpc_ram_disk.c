/*this programe can be tell you about the speed of your pc based on
 RAM and Hard disk.
Very slow   = 2 RAM + HDD
slow        = 4 RAM + HDD ||2 RAM + SSD
Normal slow = 4 RAM + SSD ||8 RAM + HDD
Fast        = 8 RAM + SSD
Very fast   = 16 RAM + SSD
*/
#include <stdio.h>
int main()
{
    // variables :
    int RAM, HD, vs;
    char HDD, SSD;
    HDD = 0;
    SSD = 1;
    HD = HDD || SSD;
    // input :
    printf("Enter GB number of RAM in your pc \n");
    scanf("%d", &RAM);
    printf("for HDD enter 0\n");
    printf("for SSD enter 1\n");
    scanf("%d", &HD);
    // condtions/output:
    if (RAM <= 2 && HD == 0)
    {
        printf("your computer is very slow\n");
    }
    else if ((RAM <= 4 && HD == 0) || (RAM <= 2 && HD == 1))
    {
        printf("your computer is Slow\n");
    }
    else if ((RAM <= 4 && HD == 1) || (RAM <= 8 && HD == 0))
    {
        printf("your computer is Normal\n");
    }
    else if (RAM <= 8 && HD == 1)
    {
        printf("your computer is Fast\n");
    }
    else if (RAM > 8 && HD == 1)
    {
        printf("your computer is very fast\n");
    }
    else
    {
        printf("try again!");
    }
}

//    if(HD==1){
//    printf(" hard disk is SSD\n");
//    }
//    else if(HD==0){
//    printf(" hard disk is HDD\n");
//    }