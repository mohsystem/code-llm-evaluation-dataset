#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int size, int target) {
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int *countSmaller(int *nums, int numsSize, int *returnSize) {
    int *counts = (int *)malloc(numsSize * sizeof(int));
    int *sortedArr = (int *)malloc(numsSize * sizeof(int));
    int sortedSize = 0;

    for (int i = numsSize - 1; i >= 0; i--) {
        int index = binarySearch(sortedArr, sortedSize, nums[i]);
        counts[i] = index;
        memmove(&sortedArr[index + 1], &sortedArr[index], (sortedSize - index) * sizeof(int));
        sortedArr[index] = nums[i];
        sortedSize++;
    }

    *returnSize = numsSize;
    free(sortedArr);
    return counts;
}