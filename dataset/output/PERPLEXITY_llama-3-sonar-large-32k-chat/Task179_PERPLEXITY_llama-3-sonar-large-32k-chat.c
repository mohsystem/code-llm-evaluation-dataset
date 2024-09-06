// Note: C does not have a built-in deque data structure, so we will use a simple array to simulate a deque.
#include <stdio.h>

void maxSlidingWindow(int* nums, int numsSize, int k, int* output) {
    if (numsSize == 0 || k == 0) {
        return;
    }
    
    int dq[100000]; // assume max size of nums is 100000
    int front = 0, rear = 0;
    
    for (int i = 0; i < numsSize; i++) {
        while (front < rear && dq[front] < i - k + 1) {
            front++;
        }
        while (front < rear && nums[dq[rear - 1]] < nums[i]) {
            rear--;
        }
        dq[rear++] = i;
        
        if (i >= k - 1) {
            output[i - k + 1] = nums[dq[front]];
        }
    }
}