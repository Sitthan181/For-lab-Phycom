#include <stdio.h>
int main(){
    double width, length;
    scanf("%lf\n%lf", &width, &length);
    double sum = (width * 2) + (length * 2);
    printf("Perimeter of rectangle = %.04lf units", sum);

    return 0;
}
