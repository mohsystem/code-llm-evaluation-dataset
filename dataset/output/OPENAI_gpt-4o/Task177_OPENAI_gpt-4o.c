#include <stdio.h>
#include <stdlib.h>

int maxSubsequenceSum(int* nums, int numsSize, int k) {
    if (numsSize == 0) return 0;

    int* dp = (int*)malloc(numsSize * sizeof(int));
    dp[0] = nums[0];
    int* deq = (int*)malloc(numsSize * sizeof(int));
    int front = 0, back = 0;

    deq[back++] = 0;

    for (int i = 1; i < numsSize; i++) {
        while (front < back && deq[front] < i - k) {
            front++;
        }
        dp[i] = nums[i] + ((front < back) ? dp[deq[front]] : 0);
        while (front < back && dp[i] >= dp[deq[back - 1]]) {
            back--;
        }
        deq[back++] = i;
    }

    int maxSum = dp[0];
    for (int i = 1; i < numsSize; i++) {
        if (dp[i] > maxSum) {
            maxSum = dp[i];
        }
    }

    free(dp);
    free(deq);

    return maxSum;
}

int main() {
    int nums1[] = {10, 2, -10, 5, 20};
    int k1 = 2;
    printf("%d\n", maxSubsequenceSum(nums1, 5, k1)); // Output: 37

    int nums2[] = {-1, -2, -3};
    int k2 = 1;
    printf("%d\n", maxSubsequenceSum(nums2, 3, k2)); // Output: -1

    int nums3[] = {10, -2, -10, -5, 20};
    int k3 = 2;
    printf("%d\n", maxSubsequenceSum(nums3, 5, k3)); // Output: 23

    return 0;
}