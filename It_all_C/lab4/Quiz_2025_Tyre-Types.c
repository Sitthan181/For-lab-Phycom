#include <stdio.h>

int main() {
    char TT;
    scanf(" %c", &TT);

    switch (TT) {
        case 'S':
        case 's':
            printf("Soft");
            break;
        case 'M':
        case 'm':
            printf("Medium");
            break;
        case 'H':
        case 'h':
            printf("Hard");
            break;
        case 'I':
        case 'i':
            printf("Intermediate");
            break;
        case 'W':
        case 'w':
            printf("Wet");
            break;
    }

    return 0;
}