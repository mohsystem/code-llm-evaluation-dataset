
#include <stdlib.h>

int* remove_smallest(const int* numbers, int length, int* new_length) {
    if (length == 0) {
        *new_length = 0;
        return NULL;
    }
    
    int min_index = 0;
    for (int i = 1; i < length; i++) {
        if (numbers[i] < numbers[min_index]) {
            min_index = i;
        }
    }
    
    int* result = malloc((length - 1) * sizeof(int));
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (i != min_index) {
            result[j++] = numbers[i];
        }
    }
    
    *new_length = length - 1;
    return result;
}
