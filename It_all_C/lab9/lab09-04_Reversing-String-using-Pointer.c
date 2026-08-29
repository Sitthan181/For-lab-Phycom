#include <stdio.h>
#include <stdlib.h>
//#include <string dot h>

int main(){
    char *str;
    int len = 0, i;

    str = (char*) malloc(sizeof(char) * 101);

    scanf("%[^\n]", str);

    //len = strlen(str);
    char *ptr = str;
    while (*ptr != '\0'){
        len++;
        ptr++;
    }

    ptr = str + len - 1;
    while (ptr >= str){
        printf("%c", *ptr);
        ptr--;
    }

    free(str);

    return 0;
}