#include <stdio.h>

int main() {
    double price;
    int percent, amount;
    double pro1, pro2;

    scanf("%lf %d %d", &price, &percent, &amount);
    pro1 = (price * amount) * ((100.0 - percent) / 100.0);
    pro2 = (price * amount) - (price * (amount / 3));
    if (pro1 <= pro2) {
        printf("Discount %d%%\n%.2f", percent, pro1);
    }
    else {
        printf("Buy 2 Get 1\n%.2f", pro2);
    }
    return 0;
}
