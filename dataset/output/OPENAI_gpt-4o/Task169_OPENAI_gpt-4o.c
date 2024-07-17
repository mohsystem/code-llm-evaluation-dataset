#include <stdio.h>

void countSmaller(int nums[], int length, int result[]) {
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = i + 1; j < length; j++) {
            if (nums[j] < nums[i]) {
                count++;
            }
        }
        result[i] = count;
    }
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int length = sizeof(nums) / sizeof(nums[0]);
    int result[length];
    countSmaller(nums, length, result);

    for (int i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}