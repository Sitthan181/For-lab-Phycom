#include <stdio.h>
int main(){
    unsigned int n, ans = 0, i = 0;
    scanf("%u", &n);
    while (i < n){
        i++;
        ans += i;
    }
    printf("%u ", ans);
    return 0;
}