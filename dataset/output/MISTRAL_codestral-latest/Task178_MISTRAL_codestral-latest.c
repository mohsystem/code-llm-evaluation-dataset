#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int shortestSubarray(int* nums, int numsSize, int k) {
    long* prefixSum = (long*)malloc((numsSize + 1) * sizeof(long));
    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int minLength = numsSize + 1;
    int* monoQueue = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;
    for (int i = 0; i <= numsSize; i++) {
        while (front <= rear && prefixSum[i] - prefixSum[monoQueue[front]] >= k) {
            minLength = fmin(minLength, i - monoQueue[front]);
            front++;
        }
        while (front <= rear && prefixSum[i] <= prefixSum[monoQueue[rear]]) {
            rear--;
        }
        rear++;
        monoQueue[rear] = i;
    }

    free(prefixSum);
    free(monoQueue);

    return minLength <= numsSize ? minLength : -1;
}