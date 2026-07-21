#include <stdio.h>
int main() {
    double horse, wage, price;
    char car[101];
    scanf(" %[^\n]", car);
    scanf("%lf %lf %lf", &horse, &wage, &price);
    printf("%.4lf\n", horse);
    printf("%.4lf\n", wage);
    printf("%.2lf\n", price);
    printf("%s\n", car);

}
