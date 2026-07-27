#include <stdio.h>

int main() {
    float bank, cash;
    scanf("%f %f", &bank, &cash);

    char type_ed;
    float amount;
    int error_count = 0;

    while (1) {
        scanf(" %c", &type_ed);

        if (type_ed == 'E') {
            char dummy;
            scanf(" %c", &dummy);
            break;
        }

        scanf("%f", &amount);

        if (type_ed == 'D') {
            if (cash >= amount) {
                cash -= amount;
                bank += amount;
                error_count = 0;
            } else {
                error_count++;
            }
        } 
        else if (type_ed == 'W') {
            if (bank >= amount) {
                bank -= amount;
                cash += amount;
                error_count = 0;
            } else {
                error_count++;
            }
        }

        if (error_count == 3) {
            break;
        }
    }

    printf("%.2f\n", bank);
    printf("%.2f\n", cash);

    return 0;
}