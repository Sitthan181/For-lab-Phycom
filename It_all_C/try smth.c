#include <stdio.h>
int main(){
    int a = 5;
    int *p = &a;
    int **x = &p;
    printf("%d\n", *p);
    printf("%d", **x);
}