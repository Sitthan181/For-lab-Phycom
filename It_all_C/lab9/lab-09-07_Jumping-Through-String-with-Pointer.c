#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *str;
    int yow = 10, tee = 0, index = 0;
    // ทำงี้ก็ได้แต่ไม่ชอบ เขียนเยอะ (การรับและกำหนด pointer ดู //)
    // str = (char*) malloc(sizeof(char)* yow);
    scanf("%d", &yow);
    str = (char*) malloc(sizeof(char)* (yow +1));
    // char *temp = (char*) realloc(str , sizeof(char)* yow);
    // str = temp;
    scanf("%d", &tee);
    scanf(" %[^\n]", str);

    char *ptr = str;
    while (*ptr != '\0'){
        if (index % tee == 0){
        printf("%c", *ptr);
        }
        index++;
        ptr++;
    }

    free(str);
    return 0;
}