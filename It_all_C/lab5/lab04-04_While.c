#include <stdio.h>
int main(){
    int M, N = 1;
    scanf("%d", &M);
    while (M >= N)
    {
        printf("%d ", N);
        N++;
    }
    
    return 0;
}