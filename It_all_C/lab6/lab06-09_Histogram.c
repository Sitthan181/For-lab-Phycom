#include <stdio.h>
#include <ctype.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char order[1000];
    int counts[256] = {0};
    int unique_count = 0;

    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        c = tolower(c);

        if (counts[(unsigned char)c] == 0) {
            order[unique_count++] = c;
        }
        counts[(unsigned char)c]++;
    }

    for (int i = 0; i < unique_count; i++) {
        char c = order[i];
        printf("%c: %d\n", c, counts[(unsigned char)c]);
    }

    return 0;
}