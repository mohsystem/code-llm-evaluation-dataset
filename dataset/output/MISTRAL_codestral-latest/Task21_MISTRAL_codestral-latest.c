#include <stdio.h>
#include <stdlib.h>

int* remove_smallest(int* numbers, int size, int* new_size) {
    if (size == 0) {
        *new_size = 0;
        return NULL;
    }
    int smallest = numbers[0];
    int smallest_index = 0;
    for (int i = 1; i < size; i++) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
            smallest_index = i;
        }
    }
    int* result = (int*)malloc((size - 1) * sizeof(int));
    for (int i = 0, j = 0; i < size; i++) {
        if (i != smallest_index) {
            result[j++] = numbers[i];
        }
    }
    *new_size = size - 1;
    return result;
}