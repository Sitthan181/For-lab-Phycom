#include <stdio.h>

int main(){
    int num;
    float ber;
    char word ,str[21];
    scanf("%d" , &num);
    scanf("%f" , &ber);
    scanf(" %c" ,&word);
    scanf("%s" ,str);
    printf("Integer: %d\n" ,num);
    printf("Float: %.3f\n" ,ber);
    printf("Character: %c\n" ,word);
    printf("String: %s\n" ,str);
    return 0;
}
