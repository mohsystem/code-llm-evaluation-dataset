#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int *nums, int length) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    for (int i = 1; i < length; i++) {
        currentSum = (nums[i] > currentSum + nums[i]) ? nums[i] : currentSum + nums[i];
        maxSum = (maxSum > currentSum) ? maxSum : currentSum;
    }
    return maxSum;
}

int main(int argc, char *argv[]) {
    int nums[argc - 1];
    for (int i = 1; i < argc; i++) {
        nums[i - 1] = atoi(argv[i]);
    }
    printf("C: %d
", maxSubArray(nums, argc - 1));
    return 0;
}