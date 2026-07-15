#include <stdio.h>
int main(){
    char car[101];
    float price, r, oil;
    scanf(" %[^\n]" , car);
    scanf("%f" , &price);
    scanf("%f" , &r);
    scanf("%f" , &oil);
    printf("%.2f\n", price);
    printf("%.2f\n", r);
    printf("%.2f\n", oil);
    printf("%s" , car);
    return 0;
}
