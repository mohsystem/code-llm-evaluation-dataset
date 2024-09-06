#include <stdbool.h>

bool xorGame(int* nums, int numsSize) {
    int xor_all = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        xor_all ^= nums[i];
        if ((nums[i] & 1) == 0) {
            count++;
        }
    }
    return xor_all == 0 || count % 2 == 1;
}