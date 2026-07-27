#include <stdio.h>
int main() {
    int age, day;
    int price = 0;

    scanf("%d", &age);
    scanf("%d", &day);

    if (day == 4) {
        price = 100;
    } else {
        if (age <= 12) {
            price = 120;
        } else if (age <= 59) {
            price = 220;
        } else {
            price = 140;
        }
        if (day == 1 || day == 7) {
            price += 20;
        }
    }

    printf("Ticket price: %d Baht\n", price);

    return 0;
}