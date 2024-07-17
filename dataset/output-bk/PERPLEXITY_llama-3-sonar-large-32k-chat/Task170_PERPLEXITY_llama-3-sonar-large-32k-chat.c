#include <stdio.h>

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    int n = numsSize;
    long long sums[n + 1];
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (lower <= sums[j + 1] - sums[i] && sums[j + 1] - sums[i] <= upper) {
                res++;
            }
        }
    }
    return res;
}