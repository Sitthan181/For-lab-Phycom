#include <stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    if (num == 0){
        printf("Duck Type: Silent Duck");
    }
    else if (num >= 1 && num <= 10){
        printf("Duck Type: Chill Duck");
    }
    else if (num >= 11 && num <= 50){
        printf("Duck Type: Happy Duck");
    }
    else if (num > 50){
        printf("Duck Type: Talkative Duck");
    }
    else
    {
        printf("Error");
    }
    
    return 0;
}