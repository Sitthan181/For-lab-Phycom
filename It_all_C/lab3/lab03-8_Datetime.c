#include <stdio.h>

int main() {
    unsigned long long smnum;
    scanf("%llu", &smnum);

    unsigned long long day = smnum / 86400;
    unsigned long long dd = smnum % 86400;
    unsigned long long hour = dd / 3600;
    unsigned long long hh = dd % 3600;
    unsigned long long min = hh / 60;
    unsigned long long sec = hh % 60;

    printf("%llu s = %llu d %llu h %llu m %llu s", smnum, day, hour, min, sec);

    return 0;
}