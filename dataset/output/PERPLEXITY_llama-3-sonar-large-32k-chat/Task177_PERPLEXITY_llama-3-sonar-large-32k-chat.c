#include <stdio.h>
#include <limits.h>

int maxSum(int* nums, int numsSize, int k) {
    int dp[numsSize];
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = dp[i-1] > nums[i] ? dp[i-1] : nums[i];
        for (int j = 1; j <= i && j <= k; j++) {
            dp[i] = dp[i] > dp[i-j-1] + nums[i] ? dp[i] : dp[i-j-1] + nums[i];
        }
    }
    return dp[numsSize-1];
}