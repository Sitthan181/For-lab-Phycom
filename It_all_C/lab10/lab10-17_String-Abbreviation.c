#include <stdio.h>
#include <stdlib.h>

int main(){

    char str[201];
    scanf("%[^\n]", str);

    char *abbre = malloc(30 * sizeof(char));
    char *start = abbre;
    *abbre++ = str[0];
    for(int i = 0;str[i] != '\0';i++){
        if(str[i] == 32){
            *abbre++ = '.';
            *abbre++ = str[i + 1];
        }
    }
    *abbre++ = '.';
    *abbre = '\0';
    printf("%s", start);
    free(start);
    return 0;
}