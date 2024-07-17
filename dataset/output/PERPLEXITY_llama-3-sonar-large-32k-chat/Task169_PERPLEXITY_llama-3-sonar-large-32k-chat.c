#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return *(int *)b - *(int *)a;
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int *indices = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        indices[i] = i;
    }
    qsort(indices, numsSize, sizeof(int), compare);
    int *counts = (int *)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        counts[indices[i]] = i;
    }
    *returnSize = numsSize;
    return counts;
}