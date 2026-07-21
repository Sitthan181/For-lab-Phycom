#include <stdio.h>
int main() {
    int a, b;
    float ans;
    scanf("%d", &a);
    scanf("%d", &b);
    ans = (float)(a) / b;
    printf("%.02f", ans);

    return 0;
}