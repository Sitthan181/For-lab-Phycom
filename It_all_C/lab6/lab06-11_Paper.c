#include <stdio.h>
int main() {
    char paper;
    int x, y;
 
    scanf("%c%d", &paper, &x);
    scanf(" %c%d", &paper, &y);
 
    int ans = 1;
    if(x >= y){
        for (int i = 0; i < x - y; i++) {
        ans *= 2;
    }
    }
    else{
        for (int i = 0; i < y - x; i++) {
        ans *= 2;
    }
    }
 
    printf("%d", ans);
 
    return 0;
}