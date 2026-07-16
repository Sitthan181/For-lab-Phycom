#include <stdio.h>
int main() {
    float mph;
    scanf("%f", &mph);

    float kmh = mph * 1.60934;
    printf("%.2f", kmh);

    return 0;
}