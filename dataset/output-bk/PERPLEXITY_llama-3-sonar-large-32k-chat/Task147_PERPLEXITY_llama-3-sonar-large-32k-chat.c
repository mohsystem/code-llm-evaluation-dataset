#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] < nums[j + 1]) {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
}

int find_kth_largest(int nums[], int n, int k) {
    sort(nums, n);
    return nums[n - k];
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the array of integers (space separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("The kth largest element is: %d
", find_kth_largest(nums, n, k));
    return 0;
}