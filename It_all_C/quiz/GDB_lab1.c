#include "stdio.h"

int main() {
    int a = 17, b = 25, c = 50, d = 10;
    
    d = a *= c / b + 5;
    d = (a *= c) / b + 5;

    return 0;
}
