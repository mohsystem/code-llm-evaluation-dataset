#include <stdio.h>
#include <stdlib.h>

// C language does not have built-in support for dynamic arrays or sets.
// The following code uses a simple bubble sort approach to count smaller elements.
// This approach has a time complexity of O(n^2), which is not efficient for large input sizes.

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[i]) {
                count++;
            }
        }
        result[i] = count;
    }
    return result;
}