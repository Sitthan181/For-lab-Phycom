#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char *str;
    //เขียนงี้ก็ได้จะได้ไม่ต้องเขียนข้างล่าง
    //char *str = (char*) malloc(sizeof(char) * 101);
    int low = 0, up = 0, num = 0;
    str = (char*) malloc(sizeof(char) * 101);
    scanf("%[^\n]", str);

    //ให้กลับไปที่จุดเริ่มต้นของ str
    char *ptr = str;
    while (*ptr != '\0'){
        if (isupper(*ptr)){
            up++;
        } else if (islower(*ptr)){
            low++;
        } else if (isdigit(*ptr)){
            num++;
        }
        ptr++;
    }

    printf("Lowercase letters: %d\n", low);
    printf("Uppercase letters: %d\n", up);
    printf("Digits: %d\n", num);

    free(str);
    return 0;
}