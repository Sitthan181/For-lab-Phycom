#include <stdio.h>

int main() {
    float height, weight;
    scanf("%f", &height);
    scanf("%f", &weight);

    float heightM = height / 100;
    float bmi = weight / (heightM * heightM);

    printf("%f", bmi);

    return 0;
}