#include <stdio.h>

int main() {
    int age, height, weight;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int sum_age = 0, sum_height = 0, sum_weight = 0;

    for (int i = 0; i < 50; i++) {
        scanf("%d %d %d", &age, &height, &weight);

        sum_age += age;
        sum_height += height;
        sum_weight += weight;

        if (age >= 20 && height >= 160) {
            count1++;
        }
        if (age < 20 && (height <= 180 || weight >= 60)) {
            count2++;
        }
        if (age >= 30 && weight >= 40 && weight <= 80) {
            count3++;
        }
        if (age < 40 && (weight < 85 || height <= 200)) {
            count4++;
        }
    }

    printf("Age >= 20 and Height >= 160: %d\n", count1);
    printf("Age < 20 and Height <= 180 or Weight >= 60: %d\n", count2);
    printf("Age >= 30 and Weight >= 40 and Weight <= 80: %d\n", count3);
    printf("Age < 40 and Weight < 85 or Height <= 200: %d\n", count4);
    printf("Average Age: %d\n", sum_age / 50);
    printf("Average Height: %.2f\n", (float)sum_height / 50.0f);
    printf("Average Weight: %.2f\n", (float)sum_weight / 50.0f);

    return 0;
}
