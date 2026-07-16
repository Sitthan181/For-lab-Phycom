#include <stdio.h>

int main() {
    char firstname[31], lastname[31], studentID[9];
    int day, month, year;
    float gpa;

    scanf("%s", firstname);
    scanf("%s", lastname);
    scanf("%s", studentID);
    scanf("%d/%d/%d", &day, &month, &year);
    scanf("%f", &gpa);

    printf("Fullname: %s %s\n", firstname, lastname);
    printf("ID: %s\n", studentID);
    printf("DOB: %02d-%02d-%04d\n", day, month, year);
    printf("GPA: %.2f\n", gpa);

    return 0;
}
