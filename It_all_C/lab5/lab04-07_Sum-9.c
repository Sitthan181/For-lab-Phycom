#include <stdio.h>
int main(){
    int ans = 0, comming;
    scanf("%d", &comming);
    while (comming != -9) {
        ans += comming;
        scanf("%d", &comming);
    }
    printf("%d", ans);
    
    return 0;
}