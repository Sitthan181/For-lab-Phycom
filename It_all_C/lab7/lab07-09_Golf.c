#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define G 9.81

int main() {
    int theta, u;
    scanf("%d", &theta);
    scanf("%d", &u);

    double rad = (theta * PI) / 180.0;
    double sin_val = sin(rad);
    double h = (u * u * sin_val * sin_val) / (2.0 * G);

    printf("theta (degree) : %d\n", theta);
    printf("u (m/s) : %d\n", u);
    printf("h (m) : %.4f\n", h);

    return 0;
}