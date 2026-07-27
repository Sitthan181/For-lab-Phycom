#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    if (N > 0) {
        for (; N >= 0; N--)
    {
        printf("%d ", N);
    }
}
    else {
        for (; N <= 0; N++)
    {
        printf("%d ", N);
    }
    }
    return 0;
}