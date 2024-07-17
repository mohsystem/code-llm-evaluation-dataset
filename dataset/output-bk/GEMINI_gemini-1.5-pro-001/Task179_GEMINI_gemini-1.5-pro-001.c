int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize * k == 0) {
        *returnSize = 0;
        return NULL;
    }
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }

    int *left = (int*)malloc(numsSize * sizeof(int));
    int *right = (int*)malloc(numsSize * sizeof(int));
    left[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        // at each k steps, set left[i] to nums[i]
        if (i % k == 0) {
            left[i] = nums[i];
        } else {
            left[i] = (left[i - 1] > nums[i]) ? left[i - 1] : nums[i];
        }
    }

    right[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        // at each (k - 1), k - 2, etc. steps, set right[i] to nums[i]
        if ((i + 1) % k == 0) {
            right[i] = nums[i];
        } else {
            right[i] = (right[i + 1] > nums[i]) ? right[i + 1] : nums[i];
        }
    }

    *returnSize = numsSize - k + 1;
    int *output = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        output[i] = (left[i + k - 1] > right[i]) ? left[i + k - 1] : right[i];
    }

    free(left);
    free(right);
    return output;
}