#include <stdio.h>
#include <string.h>

struct Record {
    char id[10];
    char name[100];
    long salary;
    long sales;
};

int main(){
    int len;
    scanf("%d", &len);
    struct Record rec[len];
    for(int i = 0;i < len;i++){
        scanf("%s %s %ld %ld", rec[i].id, rec[i].name, &rec[i].salary, &rec[i].sales);
    }

    char target[10];
    scanf("%s", target);
    for(int i = 0;i < len;i++){
        if(strcmp(rec[i].id, target) == 0){
            printf("%s\n%s\n%ld\n%.2lf\n%ld\n%.2lf", rec[i].id, rec[i].name, rec[i].sales, rec[i].sales * 0.02, rec[i].salary, rec[i].salary + (rec[i].sales * 0.02));
            return 0;
        }
    }
    printf("ID not found !!!");
    return 0;
}