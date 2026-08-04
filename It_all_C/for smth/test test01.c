#include <stdio.h>
#define ROWS 3
#define COLS 4

int main() {
    int score[ROWS][COLS];
    int r, c;
    int max[COLS] = {0};

    for (r = 0; r < ROWS; r++){
        for (c = 0; c < COLS; c++){
            scanf("%d", &score[r][c]);
        }
    }
    for (c = 0; c < COLS; c++){
        max[c] = score[0][c];
        for (r = 0; r < ROWS; r++)
            if (score[r][c] > max[c]){
                max[c] = score[r][c];
            }
    }
    for (c = 0; c < COLS; c++){
        printf("Subject %d: %d\n", c+1, max[c]);
    }

}
