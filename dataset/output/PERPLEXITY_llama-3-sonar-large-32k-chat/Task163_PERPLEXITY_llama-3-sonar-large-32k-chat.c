#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int longestRun(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), compare);
    int longest_run = 1;
    int current_run = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - nums[i-1] == 1) {
            current_run += 1;
        } else {
            longest_run = (longest_run > current_run) ? longest_run : current_run;
            current_run = 1;
        }
    }
    return (longest_run > current_run) ? longest_run : current_run;
}

int main() {
    int nums[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", longestRun(nums, numsSize));
    return 0;
}