#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* res = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = 0;
    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; ++i) {
        while (front < rear && nums[deque[rear - 1]] <= nums[i]) {
            --rear;
        }
        deque[rear++] = i;
        if (deque[front] == i - k) {
            ++front;
        }
        if (i >= k - 1) {
            res[i - k + 1] = nums[deque[front]];
        }
    }
    free(deque);
    return res;
}

int main() {
    int nums1[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    int returnSize = 0;
    int* res1 = maxSlidingWindow(nums1, 8, k1, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", res1[i]);
    }
    printf("
");
    free(res1);

    int nums2[] = {1};
    int k2 = 1;
    int* res2 = maxSlidingWindow(nums2, 1, k2, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", res2[i]);
    }
    printf("
");
    free(res2);

    return 0;
}