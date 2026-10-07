#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[2005];
    char lower_str[2005];

    if (scanf("%2000[^\n]", str) != 1) {
        return 0;
    }

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        lower_str[i] = tolower((unsigned char)str[i]);
    }
    lower_str[len] = '\0';

    char *ptr = lower_str;
    int is_first = 1;

    while ((ptr = strstr(ptr, "cat")) != NULL) {

        int index = ptr - lower_str;

        if (!is_first) {
            printf(", ");
        }
        printf("%d", index);
        is_first = 0;

        ptr += 3; 
    }

    printf("\n");

    return 0;
}