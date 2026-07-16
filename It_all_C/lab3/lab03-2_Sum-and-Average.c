#include <stdio.h>
int main(){
    float a, b, c, d;
    float sum, avg;
    scanf("%f\n%f\n%f\n%f", &a, &b, &c, &d);
    sum = a + b + c +d;
    avg = sum/4;
    printf("Summation is %.02f\n", sum);
    printf("Average is %.03f", avg);

    return 0;
}
