#include <stdio.h>
#include <stdlib.h>

// Assuming the input list contains only integers and strings
// The function will not work correctly if the input list contains other types

int* filter_list(int* list, int list_size, int* new_size) {
    int* result = malloc(list_size * sizeof(int));
    int j = 0;
    for (int i = 0; i < list_size; i++) {
        if (list[i] >= 0) {
            result[j] = list[i];
            j++;
        }
    }
    *new_size = j;
    return result;
}