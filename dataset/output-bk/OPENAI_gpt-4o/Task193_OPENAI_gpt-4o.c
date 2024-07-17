#include <stdio.h>
#include <stdbool.h>

bool xorGame(int* nums, int numsSize) {
    int xorSum = 0;
    for (int i = 0; i < numsSize; i++) {
        xorSum ^= nums[i];
    }
    
    return xorSum == 0 || numsSize % 2 == 0;
}

int main() {
    // Testing example 1
    int nums1[] = {1, 1, 2};
    printf("%s
", xorGame(nums1, 3) ? "true" : "false");  // False
    
    // Testing example 2
    int nums2[] = {0, 1};
    printf("%s
", xorGame(nums2, 2) ? "true" : "false");  // True
    
    // Testing example 3
    int nums3[] = {1, 2, 3};
    printf("%s
", xorGame(nums3, 3) ? "true" : "false");  // True
    
    return 0;
}