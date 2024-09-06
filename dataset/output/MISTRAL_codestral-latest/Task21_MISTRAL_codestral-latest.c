#include <stdlib.h>

int* remove_smallest(int* numbers, size_t length, size_t* new_length) {
    if (length == 0) {
        *new_length = 0;
        return NULL;
    }

    int min_val = numbers[0];
    size_t min_idx = 0;

    for (size_t i = 1; i < length; i++) {
        if (numbers[i] < min_val) {
            min_val = numbers[i];
            min_idx = i;
        }
    }

    int* new_numbers = malloc(sizeof(int) * (length - 1));
    if (new_numbers == NULL) {
        *new_length = 0;
        return NULL;
    }

    for (size_t i = 0; i < min_idx; i++) {
        new_numbers[i] = numbers[i];
    }

    for (size_t i = min_idx + 1; i < length; i++) {
        new_numbers[i - 1] = numbers[i];
    }

    *new_length = length - 1;
    return new_numbers;
}