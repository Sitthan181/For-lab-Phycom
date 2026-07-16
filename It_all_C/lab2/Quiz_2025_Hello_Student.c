#include <stdio.h>

int main(){
    char fname[21] ,lname[21] ,ser[21], no[9];
    scanf("%s %s" ,fname ,lname);
    scanf("%s" ,ser);
    scanf("%s" ,no);
    printf("Hello World, my name is %s (%s)\n" ,ser ,fname);
    printf("\n");
    printf("Student ID: %s\n" ,no);
    printf("Name: %s %s\n" ,fname ,lname);
    printf("Nickname: %s" ,ser);
}
