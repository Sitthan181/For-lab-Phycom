#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 61

void normalize(char *s) {
    int i;
    int newWord = 1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            newWord = 1;
        } else {
            if (newWord) {
                s[i] = toupper(s[i]);
                newWord = 0;
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }
}

int compareWords(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    int n, i;
    if (scanf("%d", &n) != 1) return 0;
    char (*names)[MAXLEN] = malloc(n * sizeof(*names));
    if (names == NULL) {
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf(" %[^\n]", names[i]);
        normalize(names[i]);
    }

    qsort(names, n, MAXLEN, compareWords);

    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    free(names);

    return 0;
}