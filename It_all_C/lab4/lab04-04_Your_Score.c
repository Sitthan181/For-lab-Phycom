#include <stdio.h>

int main() {
    float score;

    scanf("%f", &score);

    if (score > 100 || score < 0) {
        printf("Out of Range");
    } else if (score >= 80) {
        printf("A");
    } else if (score >= 70) {
        printf("B");
    } else if (score >= 60) {
        printf("C");
    } else if (score >= 50) {
        printf("D");
    } else {
        printf("F");
    }

    return 0;
}
