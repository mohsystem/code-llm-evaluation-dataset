#include <stdio.h>

void twoSum(int* nums, int numsSize, int target, int* returnSize, int* result) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return;
            }
        }
    }
}

int main() {
    int nums1[] = {1, 2, 3};
    int target1 = 4;
    int returnSize1;
    int result1[2];
    twoSum(nums1, 3, target1, &returnSize1, result1);
    printf("[%d, %d]
", result1[0], result1[1]);

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int result2[2];
    twoSum(nums2, 3, target2, &returnSize2, result2);
    printf("[%d, %d]
", result2[0], result2[1]);

    return 0;
}