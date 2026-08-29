#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_stack(char **stack, unsigned int *stack_size, int stack_capacity, char *input) {
    // 1. ตรวจสอบว่า Stack เต็มหรือไม่
    if (*stack_size >= stack_capacity) {
        printf("ERROR: Stack Overflow\n");
        return;
    }

    // 2. จองพื้นที่ Heap Memory สำหรับเก็บ String ตามความยาวของ input (+1 สำหรับ '\0')
    stack[*stack_size] = (char*) malloc((strlen(input) + 1) * sizeof(char));

    // 3. คัดลอกข้อความจาก input ไปยังหน่วยความจำที่เพิ่งจองไว้
    strcpy(stack[*stack_size], input);

    // 4. เพิ่มขนาดของ stack_size ขึ้น 1
    (*stack_size)++;
}

void print_stack(char **stack, unsigned int stack_size) {
    if (stack_size == 0) {
        printf("Stack is empty\n");
        return;
    }
    for (unsigned int i = 0; i < (stack_size) - 1; i++)
        printf("%s -> ", stack[i]);
    printf("%s\n", stack[stack_size - 1]);
}

int main() {
    unsigned int stack_capacity, stack_size = 0;
    scanf("%u", &stack_capacity);
    // จองหน่วยความจำสำหรับ Array of Pointers
    char **stack = (char**) calloc(stack_capacity, sizeof(char*));

    char command, temp[101];
    while (1) {
        // รับคำสั่งและข้อความ โดยข้ามเครื่องหมาย : และช่องว่างที่ผู้ใช้พิมพ์มา
        scanf(" %c: %[^\n]", &command, temp);

        if (command == 'q')
            break;
        else if (command == 'w')
            push_stack(stack, &stack_size, stack_capacity, temp);
        else if (command == 's')
            print_stack(stack, stack_size);
        else if (command == 'n')
            printf("Stack Size: %u\n", stack_size);
        else
            printf("ERROR: Invalid Command\n");
    }
    print_stack(stack, stack_size);

    for (unsigned int i = 0; i < stack_size; i++) {
        free(stack[i]);
    }
    free(stack);

    return 0;
}