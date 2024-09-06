
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int constrainedSubsetSum(int* nums, int numsSize, int k) {
    int* dq = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;
    int maxSum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        if (front <= rear) {
            nums[i] += dq[front];
        }
        while (front <= rear && dq[rear] < nums[i]) {
            rear--;
        }
        if (nums[i] > 0) {
            dq[++rear] = nums[i];
        }
        if (i >= k && front <= rear && dq[front] == nums[i - k]) {
            front++;
        }
        maxSum = MAX(maxSum, nums[i]);
    }

    free(dq);
    return maxSum;
}
