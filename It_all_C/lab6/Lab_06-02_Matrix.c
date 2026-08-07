#include <stdio.h>
int main(){
    float a[3][3];
    float b[3][3];
    float result[3][3] = {0};
    for(int i = 0; i < 3;i++){
        scanf("%f %f %f",&a[i][0], &a[i][1], &a[i][2]);
    }
    for(int i = 0; i < 3;i++){
        scanf("%f %f %f",&b[i][0], &b[i][1], &b[i][2]);
    }
 
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            for(int p = 0; p < 3; p++){
                result[r][c] += a[r][p] * b[p][c];
            }
        }
    }
 
    printf("A x B\n");
    for(int i = 0; i < 3;i++){
        printf("%.2f %.2f %.2f\n",result[i][0], result[i][1], result[i][2]);
    }
 
    return 0;
}