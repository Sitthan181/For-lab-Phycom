#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = malloc(105 * sizeof(char));
    if (str == NULL) {
        return 1;
    }

    if (scanf("%100s", str) != 1) {
        free(str);
        return 0;
    }

    int changed = 1;
    while (changed) {
        changed = 0;
        int read = 0;
        int write = 0;

        while (str[read] != '\0') {
            int count = 1;
            
            while (str[read] == str[read + count]) {
                count++;
            }

            if (count > 1) {
                read += count;
                changed = 1;
            } else {
                str[write++] = str[read++];
            }
        }
        
        str[write] = '\0';

        if (changed) {
                printf("%s\n", str);
        }
    }

    free(str);
    return 0;
}