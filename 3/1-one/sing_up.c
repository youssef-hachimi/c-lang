#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int day;
    int month;
    int year;
} birthday;

typedef struct
{
    int bac_year;
    char bac_speciality;
    float bac_note;
} bac;
typedef struct
{
    char F_name[12];
    char L_name[12];
    int age;
    double CNE; // code national du etudiant
    char speciality[5];
    int phone_number;
    char email[30];
    birthday date;
    bac bac_info;
} student_ESTBM;

int main()
{
    student_ESTBM student[10];
    // remplissage
    // student 1
    int n, i;
    printf("enter the number of students:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the information of student %d !\n", i + 1);
        printf("First name : \n");
        scanf("%s", &student[i].F_name);

        printf("Last name : \n");
        scanf("%s", &student[i].L_name);

        printf("Age: \n");
        scanf("%d", &student[i].age);

        printf("CNE (massar) : \n");
        scanf("%d", &student[i].CNE);

        printf("speciality : \n");
        scanf("%s", &student[i].speciality);

        printf("birthday : \n");
        printf("day:");
        scanf("%d", &student[i].date.day);
        printf("month:");
        scanf("%d", &student[i].date.month);
        printf("year:");
        scanf("%d", &student[i].date.year);

        printf("phone number : \n");
        scanf("%d", &student[i].phone_number);

        printf("email : \n");
        scanf("%s", &student[i].email);

        printf("bac year: \n");
        scanf("%d", &student[i].bac_info.bac_year);
        printf("bac note: \n");
        scanf("%f", &student[i].bac_info.bac_note);
        printf("bac speciality : \n");
        scanf("%s", &student[i].bac_info.bac_speciality);
    }
    // system("CLS");
    // clrscr();

    // affichage:
    for (i = 0; i < n; i++)
    {
        printf("information of student %d :\n", i + 1);
        printf("First name :%s\n", student[i].F_name);
        printf("Last name :%s\n", student[i].L_name);
        printf("Age name :%d\n", student[i].age);
        printf("birth day :%d/%d/%d\n", student[i].date.day, student[i].date.month, student[i].date.year);
        printf("phone number :%d\n", student[i].phone_number);
        printf("Email :%s\n", student[i].email);
        printf("speciality:%s\n", student[i].speciality);
        printf("CNE :%s\n", student[i].CNE);
        printf("BAC :%s\n", student[i].bac_info);
    }
}

// student 2
// printf("enter the information of student 2 !\n");
// printf("First name : \n");
// scanf("%s", &student2.F_name);

// printf("Last name : \n");
// scanf("%s", &student2.L_name);

// printf("Age: \n");
// scanf("%d", &student2.age);

// printf("CNE (massar) : \n");
// scanf("%d", &student2.CNE);

// printf("bac : \n");
// scanf("%s", &student2.bac_info);

// printf("speciality : \n");
// scanf("%s", &student2.speciality);

// printf("birthday : \n");
// scanf("%d", &student2.date);

// printf("phone number : \n");
// scanf("%d", &student2.phone_number);

// printf("email : \n");
// scanf("%s", &student2.email);
