#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void push_stack(char **stack, unsigned int *stack_size, unsigned int stack_capacity, char *data);
char* pop_stack(char **stack, unsigned int *stack_size);
void print_stack(char **stack, unsigned int stack_size);

int main() {
    unsigned int stack_capacity, stack_size = 0;
    scanf("%u", &stack_capacity);
    char **stack = (char**) calloc(stack_capacity, sizeof(char*));

    char command, temp[101], *return_temp;
    while (1) {
        scanf(" %c: %[^\n]", &command, temp);

        if (command == 'q')
            break;
        else if (command == 'w')
            push_stack(stack, &stack_size, stack_capacity, temp);
        else if (command == 'p') {
            return_temp = pop_stack(stack, &stack_size);
            if (return_temp) {
                printf("Pop returns: %s\n", return_temp);
                free(return_temp);
            }
        }
        else if (command == 's')
            print_stack(stack, stack_size);
        else if (command == 'n')
            printf("Stack Size: %u\n", stack_size);
        else
            printf("ERROR: Invalid Command\n");

    }
    print_stack(stack, stack_size);

    free(stack);
    return 0;
}

// Add Top Stack
void push_stack(char **stack, unsigned int *stack_size, unsigned int stack_capacity, char *data) {
    if (*stack_size >= stack_capacity) {
        printf("ERROR: Stack Overflow\n");
        return;
    }

    char *copy = (char*) malloc(strlen(data) + 1);
    strcpy(copy, data);

    stack[*stack_size] = copy;
    (*stack_size)++;
}

// ลบ Top Stack แล้วคืนค่ากลับ
char* pop_stack(char **stack, unsigned int *stack_size) {
    if (*stack_size == 0) {
        printf("ERROR: Stack Underflow\n");
        return NULL;
    }

    char *popped = stack[*stack_size - 1];
    (*stack_size)--;

    return popped;
}

// Print Stack
void print_stack(char **stack, unsigned int stack_size) {
    if (stack_size == 0) {
        printf("Stack is empty\n");
        return;
    }

    unsigned int i;
    for (i = 0; i < stack_size; i++) {
        printf("%s", stack[i]);
        if (i != stack_size - 1)
            printf(" -> ");
    }
    printf("\n");
}
