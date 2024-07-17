#include <stdio.h>
#include <limits.h>

#define MAXN 100000

int nums[MAXN];
int dp[MAXN];
int deque[MAXN];

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSubsequenceSum(int* nums, int n, int k) {
    if (n == 0) return 0;

    dp[0] = nums[0];
    int front = 0, back = 0;
    deque[back++] = 0;

    for (int i = 1; i < n; i++) {
        if (front < back && deque[front] < i - k) {
            front++;
        }
        dp[i] = nums[i] + dp[deque[front]];
        while (front < back && dp[i] >= dp[deque[back - 1]]) {
            back--;
        }
        deque[back++] = i;
    }

    int result = INT_MIN;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }
    return result;
}

int main() {
    int nums1[] = {10, 2, -10, 5, 20};
    int nums2[] = {-1, -2, -3};
    int nums3[] = {10, -2, -10, -5, 20};
    printf("%d
", maxSubsequenceSum(nums1, 5, 2));  // 37
    printf("%d
", maxSubsequenceSum(nums2, 3, 1));  // -1
    printf("%d
", maxSubsequenceSum(nums3, 5, 2));  // 23
    return 0;
}