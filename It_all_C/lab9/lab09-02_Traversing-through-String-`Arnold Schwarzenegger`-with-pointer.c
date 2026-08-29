#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;

    // Allocate memory for the string "Arnold Schwarzenegger" (including null terminator)
    str = (char*) malloc(sizeof(char)* 22);

    // Copy "Porsche Arnold" into the allocated memory
    strcpy(str, "Arnold Schwarzenegger");

    // Print the string
    char *ptr = str;
    while (*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }

    // Free the allocated memory
    free(str);

    printf("\n");
    return 0;
}