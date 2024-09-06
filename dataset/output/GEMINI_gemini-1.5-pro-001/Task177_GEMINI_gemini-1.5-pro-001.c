#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int constrainedSubsetSum(int* nums, int numsSize, int k) {
    int n = numsSize;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    if (dp == NULL) {
        return INT_MIN; // Return INT_MIN on allocation failure
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MIN; 
    }
    dp[0] = 0;

    int* deque = (int*)malloc((n + 1) * sizeof(int));
    if (deque == NULL) {
        free(dp); // Free previously allocated memory
        return INT_MIN; // Return INT_MIN on allocation failure
    }
    int front = 0, rear = -1; 

    for (int i = 0; i < n; i++) {
        // Remove outdated elements from the deque
        while (front <= rear && deque[front] < i - k) {
            front++; 
        }
        
        // Calculate dp[i + 1] based on the maximum value in the deque
        if (front <= rear) {
            dp[i + 1] = MAX(dp[i + 1], MAX(nums[i], dp[deque[front]] + nums[i])); 
        } else {
            dp[i + 1] = MAX(dp[i + 1], nums[i]); 
        }
        
        // Maintain the deque to store indices of potential maximum values
        while (front <= rear && dp[deque[rear]] <= dp[i + 1]) {
            rear--;
        }
        rear++;
        deque[rear] = i + 1;
    }

    int maxSum = INT_MIN;
    for (int i = 1; i <= n; i++) {
        maxSum = MAX(maxSum, dp[i]);
    }

    free(dp);
    free(deque);
    return maxSum;
}