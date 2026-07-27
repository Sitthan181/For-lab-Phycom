#include <stdio.h>
int main(){
    double a, b;
    scanf("%lf,%lf", &a, &b);
    double plus = a + b;
    double mius = a - b;
    double muti = a * b;
    double dive = a / b;
    printf("The sum of the given numbers : %.06lf\n", plus);
    printf("The difference of the given numbers : %.06lf\n", mius);
    printf("The product of the given numbers : %.06lf\n", muti);
    printf("The quotient of the given numbers : %.06lf\n", dive);

    return 0;
}
