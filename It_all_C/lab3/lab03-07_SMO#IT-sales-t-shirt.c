#include <stdio.h>
int main(){
    float pd, sale, amount;
    scanf("%f %f %f", &pd, &sale, &amount);
    float price = (pd -(pd * (sale/100))) * amount;
    printf("%.02f", price);

    return 0;
}