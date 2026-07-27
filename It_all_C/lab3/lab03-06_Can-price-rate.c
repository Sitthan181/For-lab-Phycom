#include <stdio.h>
#include <math.h>
int main(){
    double price, d, high;
    scanf("%lf\n%lf\n%lf", &price, &d, &high);
    double r = d/2;
    double V = (high * 3.14159265359) * pow(r, 2);
    double bml = price / V;
    printf("Volume : %.02lfml\n", V);
    printf("Baht/ml : %.04lf", bml);

    return 0;
}
