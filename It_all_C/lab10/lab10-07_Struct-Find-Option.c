#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
struct Book {
    char name[61];
    char surname[61];
    char sex[7];
    int age;
    char id[14];
    double GPA;
    int order;   // original input position, used to break ties
};
 
int compareName(const void *a, const void *b) {
    const struct Book *x = a, *y = b;
    int r = strcmp(x->name, y->name);
    return r != 0 ? r : x->order - y->order;
}
 
int compareSur(const void *a, const void *b) {
    const struct Book *x = a, *y = b;
    int r = strcmp(x->surname, y->surname);
    return r != 0 ? r : x->order - y->order;
}
 
int compareId(const void *a, const void *b) {
    const struct Book *x = a, *y = b;
    int r = strcmp(x->id, y->id);
    return r != 0 ? r : x->order - y->order;
}
 
int main() {
    struct Book book2[20];
    char method[20];
 
    for (int i = 0; i < 20; i++) {
        scanf("%s %s %s %d %s %lf", book2[i].name, book2[i].surname,
              book2[i].sex, &book2[i].age, book2[i].id, &book2[i].GPA);
        book2[i].order = i;
    }
    scanf("%19s", method);
 
    // make the option lowercase so "Name", "SURNAME", "Id" all work
    for (int i = 0; method[i]; i++)
        method[i] = tolower((unsigned char)method[i]);
 
    if (strcmp(method, "name") == 0) {
        qsort(book2, 20, sizeof(struct Book), compareName);
    } else if (strcmp(method, "surname") == 0) {
        qsort(book2, 20, sizeof(struct Book), compareSur);
    } else if (strcmp(method, "id") == 0) {
        qsort(book2, 20, sizeof(struct Book), compareId);
    }
 
    for (int i = 0; i < 20; i++) {
        if (strcmp(book2[i].sex, "Male") == 0) {
            printf("Mr %c %s (%d) ID: %s GPA %.2lf\n", book2[i].name[0],
                   book2[i].surname, book2[i].age, book2[i].id, book2[i].GPA);
        } else {
            printf("Miss %c %s (%d) ID: %s GPA %.2lf\n", book2[i].name[0],
                   book2[i].surname, book2[i].age, book2[i].id, book2[i].GPA);
        }
    }
    return 0;
}