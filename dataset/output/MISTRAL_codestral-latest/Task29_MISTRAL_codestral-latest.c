#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numbersSize; i++) {
        for (int j = i + 1; j < numbersSize; j++) {
            if (numbers[i] + numbers[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    free(result);
    return NULL;
}