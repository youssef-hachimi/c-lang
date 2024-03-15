#include <stdio.h>
int main() {
    float cm, m;
    printf("Enter length in centimeters: ");
    scanf("%f", &cm);
    m = cm / 100;
    printf("Length in meters: %.2f m\n", m);
    return 0;
}
