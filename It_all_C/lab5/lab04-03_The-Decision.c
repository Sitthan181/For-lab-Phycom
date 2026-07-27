#include <stdio.h>
int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    if (M > N) {
    while (M >= N) {
        printf("%d ", M);
        M--;
    }
}
    else {
        while (M <= N) {
        printf("%d ", M);
        M++;
    }
}

    return 0;
}