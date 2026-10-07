#include <stdio.h>
#include <stdlib.h>

int main(){
    char *str = (char *) malloc(151 * sizeof(char));
    scanf("%[^\n]", str);
    char *ptr = str;
    char *removed = (char *) malloc(151 * sizeof(char));

    char *start = removed;
    while(*(ptr) != '\0'){
        if(*ptr != 32){
            *removed = *ptr;
            removed++;
        }
        ptr++;
    }

    *removed = '\0';
    printf("%s", start);

    free(str);
    free(start);


    return 0;
}