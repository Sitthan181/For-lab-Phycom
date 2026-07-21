#include <stdio.h>
int main() {
    char info[41];
    int g1, g2, g3, g4, g5, g6;
    float grade;

    scanf(" %[^\n]", info);
    scanf("%d %d %d %d %d %d", &g1, &g2, &g3, &g4, &g5, &g6);
    grade = ((g1 + g2 + g3 + g4 + g5 + g6) * 3) / (6.0 * 3);

    printf("Grade announcement 1/2568: %s\n", info);
    printf("GPS/GPA: %.2f", grade);

    return 0;
}