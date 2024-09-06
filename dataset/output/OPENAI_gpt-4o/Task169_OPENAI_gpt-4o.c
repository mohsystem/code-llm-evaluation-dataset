#include <stdio.h>
#include <stdlib.h>

int* countSmaller(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        result[i] = 0;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[i]) {
                result[i]++;
            }
        }
    }
    return result;
}

int main() {
    int nums[1000], numsSize = 0, input;
    while (scanf("%d", &input) == 1) {
        nums[numsSize++] = input;
        if (getchar() == '\n') break;
    }
    int* result;
    int returnSize;
    result = countSmaller(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}