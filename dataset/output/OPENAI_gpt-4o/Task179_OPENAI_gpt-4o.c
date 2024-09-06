#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return;
    }

    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    int* deq = (int*)malloc(numsSize * sizeof(int));
    int front = 0, back = 0;

    for (int i = 0; i < numsSize; i++) {
        if (front < back && deq[front] == i - k) {
            front++;
        }
        while (front < back && nums[deq[back - 1]] < nums[i]) {
            back--;
        }
        deq[back++] = i;
        if (i >= k - 1) {
            result[i - k + 1] = nums[deq[front]];
        }
    }

    // Testing output
    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", result[i]);  // [3,3,5,5,6,7] for first case and [1] for second case
    }
    printf("\n");

    // Clean up
    free(result);
    free(deq);
}

int main() {
    int nums1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    int returnSize1;
    maxSlidingWindow(nums1, 8, k1, &returnSize1);  // [3,3,5,5,6,7]

    int nums2[] = {1};
    int k2 = 1;
    int returnSize2;
    maxSlidingWindow(nums2, 1, k2, &returnSize2);  // [1]

    return 0;
}