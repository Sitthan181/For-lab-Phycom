#include <stdio.h>
#include <string.h>
 
struct Book{
    char name[61];
    char surname[61];
    char sex[7];
    int age;
    char id[13];
    double GPA;
}Book1;
 
int main(){
    scanf("%s %s %s %d %s %lf", Book1.name, Book1.surname, Book1.sex, &Book1.age, Book1.id, &Book1.GPA);
    if(strcmp(Book1.sex, "Male") == 0){
        printf("Mr %c %s (%d) ID: %s GPA %.2lf", Book1.name[0], Book1.surname, Book1.age, Book1.id, Book1.GPA);
    }else{
        printf("Miss %c %s (%d) ID: %s GPA %.2lf", Book1.name[0], Book1.surname, Book1.age, Book1.id, Book1.GPA);
    }
 
    return 0;
}