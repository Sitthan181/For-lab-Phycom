#include <stdio.h>
#include <math.h>
int main(){
    float a, b;
    scanf("%f\n%f", &a, &b);
    double sum = pow(a, 2) + pow(b, 2);
    double ans = sqrt(sum);
    printf("%.02lf\n", ans);

    return 0;
}
