#include <stdio.h>

int main(){
    char name[201];
    scanf(" %[^\n]", name);
    printf("Hello, %s", name);
    printf("!");
}
