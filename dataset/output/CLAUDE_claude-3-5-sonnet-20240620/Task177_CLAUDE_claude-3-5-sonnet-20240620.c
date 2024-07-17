
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int constrainedSubsetSum(int* nums, int numsSize, int k) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    memcpy(dp, nums, numsSize * sizeof(int));
    
    int* dq = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;
    
    int maxSum = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (front <= rear && i - dq[front] > k) {
            front++;
        }
        
        if (front <= rear) {
            dp[i] = MAX(dp[i], nums[i] + dp[dq[front]]);
        }
        
        while (front <= rear && dp[dq[rear]] <= dp[i]) {
            rear--;
        }
        
        if (dp[i] > 0) {
            dq[++rear] = i;
        }
        
        maxSum = MAX(maxSum, dp[i]);
    }
    
    free(dp);
    free(dq);
    
    return maxSum;
}
