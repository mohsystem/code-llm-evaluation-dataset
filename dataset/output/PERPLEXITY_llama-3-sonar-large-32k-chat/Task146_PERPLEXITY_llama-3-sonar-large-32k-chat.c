#include <stdio.h>

int find_missing_number(int nums[], int size) {
    int n = size + 1;
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int i = 0; i < size; i++) {
        actual_sum += nums[i];
    }
    return expected_sum - actual_sum;
}

int main() {
    int nums[100];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array of numbers: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }
    int missing_number = find_missing_number(nums, size);
    printf("The missing number is: %d\n", missing_number);
    return 0;
}