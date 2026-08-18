#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int max_size = 10; // สมมุติว่ารู้ว่าโจทย์ให้สูงสุดไม่เกิน 10 ตัว
    int arr[10];
    int n;

    // 1. รับจำนวนรอบที่ต้องรับข้อมูล (เช่น 5)
    if (scanf("%d", &n) != 1) return 0;

    // 2. วนลูปรับข้อมูลตามจำนวน n ตัว
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. เรียงลำดับข้อมูลจำนวน n ตัว
    qsort(arr, n, sizeof(int), compare);

    // 4. แสดงผลลัพธ์
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}