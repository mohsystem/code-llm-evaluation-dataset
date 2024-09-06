#include <stdio.h>
#include <stdlib.h>

int maxSumSubsequence(int* nums, int numsSize, int k) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = dp[i-1] > nums[i] ? dp[i-1] : nums[i];
        for (int j = i-1; j >= (i-k-1 > -1 ? i-k-1 : -1); j--) {
            dp[i] = dp[i] > dp[j] + nums[i] ? dp[i] : dp[j] + nums[i];
        }
    }
    int maxSum = dp[0];
    for (int i = 1; i < numsSize; i++) {
        maxSum = maxSum > dp[i] ? maxSum : dp[i];
    }
    free(dp);
    return maxSum;
}