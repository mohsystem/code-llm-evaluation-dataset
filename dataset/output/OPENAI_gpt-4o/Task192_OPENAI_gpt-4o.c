#include <stdio.h>
#include <stdbool.h>

bool xorGame(int* nums, int numsSize) {
    int xor_sum = 0;
    for(int i = 0; i < numsSize; i++) {
        xor_sum ^= nums[i];
    }
    return xor_sum == 0 || numsSize % 2 == 0;
}

int main() {
    int nums1[] = {1, 1, 2};
    int nums2[] = {0, 1};
    int nums3[] = {1, 2, 3};
    printf("%d\n", xorGame(nums1, 3));  // Output: 0 (false)
    printf("%d\n", xorGame(nums2, 2));  // Output: 1 (true)
    printf("%d\n", xorGame(nums3, 3));  // Output: 1 (true)
    return 0;
}