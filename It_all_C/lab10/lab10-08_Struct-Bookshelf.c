#include <stdio.h>
#include <string.h>

struct Book {
    char id[10];
    char name[100];
    char author[100];
};

int main(){

    int i;
    char toFind[10];
    int found = 0;
    scanf("%d", &i);
    scanf("%s", toFind);
    struct Book bookshelf[i];

    for (int j = 0; j < i; j++)
    {
        scanf("%s %s %s", bookshelf[j].id, bookshelf[j].name, bookshelf[j].author);
    }

    for (int k = 0; k < i; k++)
    {
        if(strcmp(bookshelf[k].id, toFind) == 0){
            printf("%s %s %s", bookshelf[k].id, bookshelf[k].name, bookshelf[k].author);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Not Found");
    }
    
    

    return 0;
}