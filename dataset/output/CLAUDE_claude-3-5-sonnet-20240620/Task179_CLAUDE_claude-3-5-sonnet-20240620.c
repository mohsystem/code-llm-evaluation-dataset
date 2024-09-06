
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (nums == NULL || numsSize == 0 || k <= 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int ri = 0;
    
    int* deque = (int*)malloc(sizeof(int) * numsSize);
    int front = 0, rear = -1;
    
    for (int i = 0; i < numsSize; i++) {
        while (front <= rear && deque[front] < i - k + 1) {
            front++;
        }
        
        while (front <= rear && nums[deque[rear]] < nums[i]) {
            rear--;
        }
        
        deque[++rear] = i;
        
        if (i >= k - 1) {
            result[ri++] = nums[deque[front]];
        }
    }
    
    free(deque);
    *returnSize = ri;
    return result;
}
