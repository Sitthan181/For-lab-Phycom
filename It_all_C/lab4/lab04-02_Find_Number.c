#include <stdio.h>

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
// || = หรือ คือ b<=a<=c หรือ c<=a<=b ให้ตอบ a smth like that
    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        printf("%.2f", a);
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        printf("%.2f", b);
    } else {
        printf("%.2f", c);
    }

    return 0;
}
