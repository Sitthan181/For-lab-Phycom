#include <stdio.h>
 
int main() {
    int M[] = {2, 20, 8, 10, 4, 6, 16, 18};
    int N[] = {1, 3, 9, 7, 11, 15, 19};
    int n;
    int count = 0;
 
    while (1) {
        scanf("%d", &n);
        if (n > 0 && n < 21) {
            break;
        }
    }
 
    if (n > 0 && n < 21) {
        for (int i = 0; i <= 7; i++) {
            if (n == M[i]) {
                count++;
                printf("%d is in M at index [%d]\n", n, i);
                break;
            }
        }
 
        for (int i = 0; i <= 6; i++) {
            if (n == N[i]) {
                count++;
                printf("%d is in N at index [%d]\n", n, i);
                break;
            }
        }
 
        if (count == 0) {
            printf("%d is not in neither M nor N\n", n);
        }
    }
 
    return 0;
}