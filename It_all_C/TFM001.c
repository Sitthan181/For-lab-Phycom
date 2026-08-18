#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[10];
    int count = 0;
    while (count < 10 && scanf("%d", &arr[count]) == 1) {
        count++;
    }
    qsort(arr, count, sizeof(int), compare);

    printf("ข้อมูลที่เรียงจากน้อยไปมาก: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}