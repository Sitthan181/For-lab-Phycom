#include <stdio.h>
int main(){
    int num_review ;
    int i;
    int Min;
    int Max;
    int sum = 0;
    float avg = 0.0;
    scanf("%d", &num_review);
    int score[num_review];
    for (i=0; i < num_review; i++){
        scanf("%d", &score[i]);
        sum += score[i];
        if (i == 0){
            Min = score[i];
            Max = score[i];
        } else {
            if (score[i] >= Max){
                Max = score[i];
            }
            if (score[i] <= Min){
                Min = score[i];
        }
    }
}
    avg = (float)sum/num_review;
    printf("Max: %d\n", Max);
    printf("Min: %d\n", Min);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f", avg);
    return 0;
}
