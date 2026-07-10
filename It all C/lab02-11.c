#include <stdio.h>

int main(){
    char ans[6];
    char num[6];
    scanf("%5s" ,num);
    ans[0] = num[2];
    ans[1] = num[3];
    ans[2] = num[4];
    ans[3] = num[0];
    ans[4] = num[1];
    ans[5] = '\0';
    printf("%s\n" ,ans);
    return 0;
}
