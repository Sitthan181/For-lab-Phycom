#include <stdio.h>
#include <string.h>

int main() {
    int max_size;
    scanf("%d", &max_size);

    char stack[100][100];
    int count = 0;
    char input[100];

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }

        if (strcmp(input, "w:") == 0) {
            char value[100];
            scanf("%s", value);

            if (count >= max_size) {
                printf("ERROR: Stack Overflow\n");
            } else {
                strcpy(stack[count], value);
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s", stack[i]);
        if (i < count - 1) {
            printf(" -> ");
        }
    }
    printf("\n");

    return 0;
}