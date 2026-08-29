#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *arr;

    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int*) malloc(sizeof(int) * size);

    // Populate the array
    for (i = 0; i < size; i++)
        *(arr + i) = i + 1;

    int *ptr = arr;  // Point to the first element of the array

    // Print the array in order using pointers
    printf("Array elements in order: ");
    while (ptr < arr + size) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    // Print the array in reverse using pointers
    ptr = arr + size - 1;   // Move pointer to the last element
    printf("Array elements in reverse: ");
    while (ptr >= arr) {
        printf("%d ", *ptr);
        ptr--;
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}