#include <stdio.h>
int main() {
    char word[101];
    int n;
    scanf("%[^\n]", word);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("%c", word[i]);
    }
 
    return 0;
}