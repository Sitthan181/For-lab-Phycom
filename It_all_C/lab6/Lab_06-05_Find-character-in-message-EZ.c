#include <stdio.h>
int main(){
    char str[301];
    char n;
    int keep[301] = {0};
    scanf("%[^\n]", &str);
    scanf(" %c",&n);
    int i = 0;
    int count = 0;
    char small = n;
    char big = n;
    if(n >= 'A' && n <= 'Z'){
        small = n + 32;
    }
    else if (n >= 'a' && n <= 'z'){
        big = n - 32;
    }
    while(str[i] != '\0'){
        char c = str[i];
        if(c == small || c == big){
            keep[count] = i+1;
            count++;
        }
 
        i++;
    }
    if(count != 0){
    printf("There is/are %d \"%c\" in the above sentences.\n",count, n);
    printf("Position: ");
    for(int i = 0; i < count; i++){
        if(i + 1 == count){
            printf("%d",keep[i]);
        }
        else{
            printf("%d, ",keep[i]);
        }
    }
}
else{
    printf("Not found.");
}
    return 0;
}
