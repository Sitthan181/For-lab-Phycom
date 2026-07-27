#include <stdio.h>

int main() {
    double km;
    scanf("%lf", &km);

    if (km < 0 || km > 58.855) {
        printf("InValid\n");
    }
    else if (km <= 5.032) {
        printf("Bangkok\n");
    }
    else if (km <= 35.477) {
        printf("Samut Prakarn\n");
    }
    else if (km <= 52.900) {
        printf("Chachoengsao\n");
    }
    else if (km <= 58.855) {
        printf("Chon Buri\n");
    }

    return 0;
}