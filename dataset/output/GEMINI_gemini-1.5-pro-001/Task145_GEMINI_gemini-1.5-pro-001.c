#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_so_far = INT_MIN, max_ending_here = 0;
    int start_index = 0, end_index = 0, j = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start_index = j;
            end_index = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            j = i + 1;
        }
    }

    printf("Maximum contiguous subarray: ");
    for (int i = start_index; i <= end_index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}