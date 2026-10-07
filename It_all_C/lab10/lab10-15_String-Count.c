#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char target;
    scanf(" %c", &target);

    char str[151];
    scanf(" %[^\n]", str);

    int count = 0;
    char target_lower = tolower(target);

    for (int i = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) == target_lower) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
