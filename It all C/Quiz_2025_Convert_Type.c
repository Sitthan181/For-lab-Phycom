#include <stdio.h>

int main() {
    int intNumber;
    float floatNumber;
    char charValue;

    scanf("%d", &intNumber);
    scanf("%f", &floatNumber);
    scanf(" %c", &charValue);

    printf("%.3f\n", (float)intNumber);
    printf("%d\n", (int)floatNumber);
    printf("%d\n", (int)charValue);

    return 0;
}
