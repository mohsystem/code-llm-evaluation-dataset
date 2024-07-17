#include <stdio.h>
#include <stdlib.h>

void maxSlidingWindow(int* nums, int numsSize, int k, int* res) {
    if (nums == NULL || numsSize == 0) return;
    int dq[numsSize];
    int front = 0, rear = 0;
    for (int i = 0; i < numsSize; i++) {
        while (front < rear && dq[front] < i - k + 1) front++;
        while (front < rear && nums[dq[rear - 1]] < nums[i]) rear--;
        dq[rear++] = i;
        if (i >= k - 1) res[i - k + 1] = nums[dq[front]];
    }
}