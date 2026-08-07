#include <stdio.h>
int main(){
    char w[101];
    char re[101];
    scanf("%s",w);
    int count = 0;
    while(1){
        if(w[count] == '\0'){
            break;
        }
        count++;
    }
    int j = 0;
    for(int i = count-1; i >= 0; i--){
        re[j] = w[i];
        j++;
    }
    int check = 0;
    for(int i = 0; i < count;i++){
        if(re[i] == w[i]){
            check++;
        }
    }
    if(check == count){
        printf("It is Palindrome.");
    }
    else{
        printf("It is not Palindrome.");
    }
 
 
    return 0;
}