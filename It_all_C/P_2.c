#include <stdio.h>

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);

    long long warps = (x + y - 1) / y;
    long long energy = warps * 10;
    long long dorayaki = (energy + 129) / 130;

    if (dorayaki <= 0) {
        printf("%lld 0\n", energy);
        return 0;
    }

    printf("%lld %lld\n", energy, dorayaki);

    return 0;
}
