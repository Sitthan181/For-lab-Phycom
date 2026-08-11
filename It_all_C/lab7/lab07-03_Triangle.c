#include <stdio.h>
#include <math.h>
double perimeter(double a, double b);
double area(double a, double b);

int main(){
    double a, b, Pe, Ae;
    scanf("%lf %lf", &a, &b);
    Pe = perimeter(a, b);
    Ae = area(a, b);
    printf("Perimeter: %.2f\n", Pe);
    printf("Area: %.2f\n", Ae);
    return 0;
}

double perimeter(double a, double b){
    double c, c2, ans;
    c = pow(a, 2) + pow(b, 2);
    c2 = sqrt(c);
    ans = a + b + c2;
    return ans;
}

double area(double a, double b){
    double ans;
    ans = 0.5 * (a * b);
    return ans;
}
