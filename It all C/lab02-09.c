#include <stdio.h>

int main(){
    char ch1 ,ch2 ,ch3 ,ch4 ,ch5;
    scanf(" %c", &ch1);
    scanf(" %c", &ch2);
    scanf(" %c", &ch3);
    scanf(" %c", &ch4);
    scanf(" %c", &ch5);

    ch1 = ch1+1;
    ch3 = ch3+1;
    ch5 = ch5+1;

    printf("%c\n", ch1);
    printf("%c\n", ch2);
    printf("%c\n", ch3);
    printf("%c\n", ch4);
    printf("%c\n", ch5);
    return 0;
}
