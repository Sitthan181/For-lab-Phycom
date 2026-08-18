#include <stdio.h>
int main(){
    char car[51], car2[51];
    int t[7], t2[7];
    int avg_tt1 = 0, avg_tt2 = 0, avg_td1 = 0, avg_td2 = 0, d_lt1 = 0, d_lt2 = 0, d_et = 0;
    scanf(" %[^\n]", car);
    for (int i = 0; i < 7; i++){
        scanf("%d", &t[i]);
        avg_tt1 = avg_tt1 + t[i];
    }
    scanf(" %[^\n]", car2);
    for (int i = 0; i < 7; i++){
        scanf("%d", &t2[i]);
        avg_tt2 = avg_tt2 + t2[i];
    }
    avg_td1 = avg_tt1 / 7;
    avg_td2 = avg_tt2 / 7;
    for (int i = 0; i < 7; i++){
        if (t[i] < t2[i]){
            d_lt1++;
        } else if (t[i] > t2[i]){
            d_lt2++;
        } else {
            d_et++;
        }
    }
    printf("%s: %d minutes, average %d minutes/day\n", car, avg_tt1, avg_td1);
    printf("%s: %d minutes, average %d minutes/day\n", car2, avg_tt2, avg_td2);
    printf("Faster days - %s: %d, %s: %d, Equal: %d", car, d_lt1, car2, d_lt2, d_et);
    return 0;
}