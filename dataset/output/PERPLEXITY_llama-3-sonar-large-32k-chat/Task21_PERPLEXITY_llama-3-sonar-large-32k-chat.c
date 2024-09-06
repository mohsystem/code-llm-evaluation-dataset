#include <stdio.h>
#include <stdlib.h>

int* removeSmallest(int* numbers, int size, int* newSize) {
    if (size == 0) {
        *newSize = 0;
        return (int*)malloc(0);
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }
    }
    int* result = (int*)malloc((size - 1) * sizeof(int));
    for (int i = 0; i < minIndex; i++) {
        result[i] = numbers[i];
    }
    for (int i = minIndex + 1; i < size; i++) {
        result[i - 1] = numbers[i];
    }
    *newSize = size - 1;
    return result;
}