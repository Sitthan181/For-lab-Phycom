#include <stdio.h>

int main() {
    char grade;

    scanf("%c", &grade);

    switch (grade) {
        case 'A':
        case 'a':
            printf("Genius\n");
            break;
        case 'B':
        case 'b':
            printf("Good\n");
            break;
        case 'C':
        case 'c':
            printf("Try Harder\n");
            break;
        case 'D':
        case 'd':
            printf("Very Bad\n");
            break;
        case 'F':
        case 'f':
            printf("Fail\n");
            break;
        default:
            printf("Invalid Input\n");
            break;
    }

    return 0;
}
