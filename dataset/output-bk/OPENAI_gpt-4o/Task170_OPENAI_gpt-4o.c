#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(long*)a - *(long*)b);
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long *prefixSums = (long*)malloc((numsSize + 1) * sizeof(long));
    prefixSums[0] = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        prefixSums[i + 1] = prefixSums[i] + nums[i];
    }
    
    int count = 0;
    
    for (int i = 0; i <= numsSize; ++i) {
        for (int j = i + 1; j <= numsSize; ++j) {
            long diff = prefixSums[j] - prefixSums[i];
            if (diff >= lower && diff <= upper) {
                ++count;
            }
        }
    }
    
    free(prefixSums);
    return count;
}

int main() {
    int nums[] = {-2, 5, -1};
    int lower = -2;
    int upper = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d
", countRangeSum(nums, numsSize, lower, upper));  // Output: 3
    return 0;
}