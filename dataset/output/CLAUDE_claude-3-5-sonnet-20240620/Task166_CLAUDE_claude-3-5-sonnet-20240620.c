
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* posNegSort(int* arr, int arrSize, int* returnSize) {
    int* pos = (int*)malloc(arrSize * sizeof(int));
    int posSize = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            pos[posSize++] = arr[i];
        }
    }
    
    qsort(pos, posSize, sizeof(int), compare);
    
    int* result = (int*)malloc(arrSize * sizeof(int));
    int posIndex = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            result[i] = pos[posIndex++];
        } else {
            result[i] = arr[i];
        }
    }
    
    *returnSize = arrSize;
    free(pos);
    return result;
}
