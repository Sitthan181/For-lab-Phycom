#include <stdio.h>
#include <math.h>

double cal(double a, double b);

int main(){
    double a, b;
    double c;
    scanf("%lf %lf", &a, &b);
    c = cal(a, b);
    printf("sqrt(%.0lf^2+%.0lf^2)=%.2lf", a, b, c);
    return 0;
}

double cal(double a, double b){
    double c, ans;
    c = hypot(a, b);
    return c;
}