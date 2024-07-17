#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int constrainedSubsetSum(int* nums, int numsSize, int k){
    int n = numsSize;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = INT_MIN;
    }
    int *queue = malloc((k+1)*sizeof(int));
    int front = 0, rear = 0;
    for (int i = 1; i <= n; ++i) {
        while (front < rear && i - queue[front] > k + 1) {
            front++;
        }
        dp[i] = MAX(dp[i - 1], (front == rear ? 0 : dp[queue[front]]) + nums[i - 1]);
        while (front < rear && dp[queue[rear - 1]] <= dp[i]) {
            rear--;
        }
        queue[rear++] = i;
    }
    free(queue);
    return dp[n];
}