#include <stdio.h> //Try this -> Work just fine

int main() {
    int num;
    scanf("%d", &num);

    int digit[5];
    digit[0] = num / 10000;
    digit[1] = (num / 1000) % 10;
    digit[2] = (num / 100) % 10;
    digit[3] = (num / 10) % 10;
    digit[4] = num % 10;
    int prefix = 0;
    char sp = ' ';

    for (int i = 0; i < 5; i++) {
        prefix = prefix * 10 + digit[i];
        printf("%*d", 2 * i + 1, prefix);
        if (i < 4) {
            printf("%*c", 79 - 2 * i, sp);
        }
    }

    return 0;
}
/*#include <stdio.h> This one work

int main() {
    int num;
    scanf("%d", &num);

    char sp = ' ';
    int d1 = num / 10000;
    int d2 = (num / 1000) % 10;
    int d3 = (num / 100) % 10;
    int d4 = (num / 10) % 10;
    int d5 = num % 10;

    int prex1 = d1;
    int prex2 = prex1 * 10 + d2;
    int prex3 = prex2 * 10 + d3;
    int prex4 = prex3 * 10 + d4;
    int prex5 = prex4 * 10 + d5;

    printf("%1d", prex1);
    printf("%79c" ,sp);
    printf("%3d", prex2);
    printf("%77c" ,sp);
    printf("%5d", prex3);
    printf("%75c" ,sp);
    printf("%7d", prex4);
    printf("%73c" ,sp);
    printf("%9d", prex5);

    return 0;
}*/
