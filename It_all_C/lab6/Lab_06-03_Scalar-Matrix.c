#include <stdio.h>
int main(){
    float a[3][3];
    float result[3][3] = {0};
    int sca = 0;
    int nosca = 0;
    for(int i = 0; i < 3;i++){
        scanf("%f %f %f",&a[i][0], &a[i][1], &a[i][2]);
    }
 
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2]){
        sca++;
    }
    if(a[0][1] == 0.0 && a[0][2] == 0.0 && a[1][0] == 0.0 && a[1][2] == 0.0 && a[2][0] == 0.0 && a[2][1] == 0.0){
        nosca++;
    } 
 
 
    if(sca == 1 && nosca == 1){
       printf("This is a scalar matrix"); 
    }
    else{
        printf("This is not a scalar matrix");
    }
    return 0;
}