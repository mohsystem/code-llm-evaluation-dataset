#include <stdbool.h>

bool xorGame(int* nums, int numsSize) {
    int xor_all = 0;
    for (int i = 0; i < numsSize; i++) {
        xor_all ^= nums[i];
    }
    if (xor_all == 0) {
        return true;
    }
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            count++;
        }
    }
    return count % 2 == 0;
}