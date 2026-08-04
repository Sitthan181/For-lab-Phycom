#include <stdio.h>
int main(){
    int num, i, odd = 0, even = 0, odd_s = 0, even_s = 0;
    scanf("%d", &num);
    int ber[num];
    for (i = 0; i < num; i++){
        scanf("%d", &ber[i]);
        if (ber[i] % 2 == 0){
            even++;
            even_s += ber[i];
        } else {
            odd++;
            odd_s += ber[i];
        }
    }
    printf("Even count: %d\n", even);
    printf("Odd count: %d\n", odd);
    printf("Even sum: %d\n", even_s);
    printf("Odd sum: %d\n", odd_s);

    return 0;
}
