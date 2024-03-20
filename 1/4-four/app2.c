#include <stdio.h>

// Function to calculate age
void calculateAge(int birth_day, int birth_month, int birth_year) {
    int current_day, current_month, current_year;
    printf("Enter the current day (1-31): ");
    scanf("%d", &current_day);

    printf("Enter the current month (1-12): ");
    scanf("%d", &current_month);

    printf("Enter the current year: ");
    scanf("%d", &current_year);

    int age = current_year - birth_year;
    if (current_month < birth_month)
        age--;

    else if (current_month == birth_month && current_day < birth_day)
        age--;

    printf("You are %d years old.\n", age);
}

int main() {
    int birth_day, birth_month, birth_year;

    printf("Enter your birth day (1-31): ");
    scanf("%d", &birth_day);

    printf("Enter your birth month (1-12): ");
    scanf("%d", &birth_month);

    printf("Enter your birth year: ");
    scanf("%d", &birth_year);

    calculateAge(birth_day, birth_month, birth_year);

    return 0;
}
