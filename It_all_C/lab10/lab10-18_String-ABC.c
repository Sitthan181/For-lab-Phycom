#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ฟังก์ชันเปรียบเทียบค่า char สำหรับ qsort ตามค่า ASCII
int compare(const void *a, const void *b) {
    return (*(const char *)a - *(const char *)b);
}

int main(void) {
    char input[205];
    char filtered[205];
    
    // รับข้อความ 1 บรรทัด (ไม่เกิน 200 ตัวอักษร)
    if (scanf("%[^\n]", input) != 1) {
        return 0;
    }

    // กรองช่องว่างออกตามตัวอย่าง Sample Case
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != ' ') {
            filtered[len++] = input[i];
        }
    }
    filtered[len] = '\0';

    // เรียงลำดับจากน้อยไปมากตามค่า ASCII ด้วย qsort
    qsort(filtered, len, sizeof(char), compare);

    // แสดงผลลัพธ์
    printf("%s\n", filtered);

    return 0;
}