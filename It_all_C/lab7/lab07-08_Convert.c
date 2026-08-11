#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
void toggleCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char str1[105], str2[105];

    scanf(" %[^\n]", str1);
    scanf(" %[^\n]", str2);

    toggleCase(str1);
    toggleCase(str2);

    printf("*** Results ***\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("***************\n");

    if (strcasecmp(str1, str2) == 0) {
        printf("Both strings are the same.\n");
    } else {
        printf("Both strings are not the same.\n");
    }

    return 0;
}