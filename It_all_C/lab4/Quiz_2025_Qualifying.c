#include <stdio.h>
#include <string.h>

int main() {
    float min_time = 999999;
    char best_driver[50];

    float current_time;
    char current_driver[50];

    for (int i = 0; i < 3; i++) {
        scanf("%f %[^\n]", &current_time, current_driver);
        if (current_time < min_time) {
            min_time = current_time;
            strcpy(best_driver, current_driver);
        }
    }
    printf("%s is Fastest : %.3f\n", best_driver, min_time);

    return 0;
}