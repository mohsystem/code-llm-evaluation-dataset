
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int shortestSubarray(int* nums, int numsSize, int k) {
    long long* prefixSum = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    int* deque = (int*)malloc((numsSize + 1) * sizeof(int));
    int front = 0, rear = -1;
    int shortest = INT_MAX;
    
    for (int i = 0; i <= numsSize; i++) {
        while (front <= rear && prefixSum[i] - prefixSum[deque[front]] >= k) {
            shortest = MIN(shortest, i - deque[front]);
            front++;
        }
        
        while (front <= rear && prefixSum[i] <= prefixSum[deque[rear]]) {
            rear--;
        }
        
        deque[++rear] = i;
    }
    
    free(prefixSum);
    free(deque);
    
    return shortest == INT_MAX ? -1 : shortest;
}
