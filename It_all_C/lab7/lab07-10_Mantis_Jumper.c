#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("method = 1\n");
        return 0;
    }
    if (n == 2) {
        printf("method = 2\n");
        return 0;
    }

    long long prev2 = 1;
    long long prev1 = 2;
    long long current_ways;

    for (int i = 3; i <= n; i++) {
        current_ways = prev1 + prev2;
        prev2 = prev1;
        prev1 = current_ways;
    }

    printf("method = %lld\n", current_ways);

    return 0;
}