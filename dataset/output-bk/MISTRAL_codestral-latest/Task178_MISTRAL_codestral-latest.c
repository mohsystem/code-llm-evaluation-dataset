#include <stdio.h>
#include <stdlib.h>

int shortestSubarray(int* nums, int numsSize, int k) {
    long* prefixSum = (long*)malloc((numsSize + 1) * sizeof(long));
    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int ans = numsSize + 1;
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;
    for (int i = 0; i <= numsSize; i++) {
        while (front <= rear && prefixSum[i] - prefixSum[deque[front]] >= k) {
            ans = fmin(ans, i - deque[front]);
            front++;
        }
        while (front <= rear && prefixSum[i] <= prefixSum[deque[rear]]) {
            rear--;
        }
        rear++;
        deque[rear] = i;
    }

    free(prefixSum);
    free(deque);

    return ans <= numsSize ? ans : -1;
}