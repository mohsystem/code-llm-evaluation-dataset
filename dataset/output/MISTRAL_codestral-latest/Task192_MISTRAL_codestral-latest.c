#include <stdbool.h>

bool xorGame(int* nums, int numsSize) {
    int xor = 0;
    for (int i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }

    if (xor == 0) {
        return false;
    } else if (numsSize % 2 == 0) {
        return false;
    } else {
        return true;
    }
}