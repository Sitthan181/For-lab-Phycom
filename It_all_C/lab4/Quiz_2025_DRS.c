#include <stdio.h>

int main() {
    int safe_stat;
    float gap;
    int current_lap, sc;
    int fail_count = 0;

    scanf("%d", &safe_stat);
    scanf("%f", &gap);
    scanf("%d %d", &current_lap, &sc);

    if (safe_stat != 1) {
        fail_count++;
    }
    if (gap >= 1.0) {
        fail_count++;
    }
    if (current_lap <= 2) {
        fail_count++;
    }
    if (current_lap - sc < 2) {
        fail_count++;
    }
    if (fail_count != 0) {
        printf("DRS not allowed %d\n", fail_count);
    } else {
        printf("DRS allowed\n");
    }

    return 0;
}