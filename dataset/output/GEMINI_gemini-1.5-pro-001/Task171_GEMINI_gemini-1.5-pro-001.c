int reversePairs(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > 2 * nums[j]) {
                count++;
            }
        }
    }
    return count;
}