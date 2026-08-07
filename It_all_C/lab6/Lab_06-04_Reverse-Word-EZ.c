#include <stdio.h>
int main(){
    char name[101];
    scanf("%[^\n]",name);
    int count = 0;
    while(1){
        if(name[count] == '\0'){
            break;
        }
            count++;
    }
    for(int i = count-1; i >= 0; i--){
        printf("%c",name[i]);
    }
 
    return 0;
}