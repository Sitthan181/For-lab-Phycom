#include <stdio.h>
int main() {
    unsigned int a[5];
    unsigned int num;
  
    for(int i = 0; i < 5; i++){
        scanf("%u", &a[i]);
    }
    scanf("%u",&num);
    printf("Value at index %u is %u", num, a[num]);
  
    return 0;
}
