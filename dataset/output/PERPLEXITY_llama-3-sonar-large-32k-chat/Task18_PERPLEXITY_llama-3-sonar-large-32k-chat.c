#include <stdio.h>
#include <stdlib.h>

int binaryArrayToNumber(int* arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result = (result << 1) | arr[i];
    }
    return result;
}