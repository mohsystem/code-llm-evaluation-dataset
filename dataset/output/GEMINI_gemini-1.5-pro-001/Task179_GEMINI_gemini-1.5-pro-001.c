#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }
    
    int *max_left = (int*)malloc(numsSize * sizeof(int));
    int *max_right = (int*)malloc(numsSize * sizeof(int));
    max_left[0] = nums[0];
    max_right[numsSize - 1] = nums[numsSize - 1];

    for (int i = 1; i < numsSize; i++) {
        max_left[i] = (i % k == 0) ? nums[i] : max(max_left[i - 1], nums[i]);
        int j = numsSize - i - 1;
        max_right[j] = ((j + 1) % k == 0) ? nums[j] : max(max_right[j + 1], nums[j]);
    }

    *returnSize = numsSize - k + 1;
    int *result = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = max(max_right[i], max_left[i + k - 1]);
    }

    free(max_left);
    free(max_right);
    return result;
}