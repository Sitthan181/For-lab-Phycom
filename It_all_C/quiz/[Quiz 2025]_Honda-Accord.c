#include <stdio.h>

int main() {
    char model_name[256];
    int n;
    int speeds[15];
    int current_speed;

    scanf(" %[^\n]", model_name);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &speeds[i]);
    }

    scanf("%d", &current_speed);

    printf("%s\n", model_name);

    if (current_speed > speeds[n - 1]) {
        printf("> %d\n", speeds[n - 1]);
    } else if (current_speed == speeds[0]) {
        printf("%d - %d\n", speeds[0], speeds[1]);
    } else {
        for (int i = 1; i < n; i++) {
            if (current_speed <= speeds[i]) {
                printf("%d - %d\n", speeds[i - 1], speeds[i]);
                break;
            }
        }
    }

    return 0;
}