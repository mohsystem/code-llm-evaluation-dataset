#include <stdio.h>

int find_missing_number(int* nums, int size) {
    int n = size + 1;
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return total - sum;
}

int main() {
    int nums[100];
    int i = 0;
    printf("Enter the array of unique integers: ");
    while (scanf("%d", &nums[i]) == 1) {
        i++;
        if (getchar() == '
') break;
    }
    printf("The missing number is: %d
", find_missing_number(nums, i));
    return 0;
}