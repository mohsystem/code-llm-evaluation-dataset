#include <stdio.h>
#include <limits.h>

void max_subarray_sum(int arr[], int n) {
    int max_so_far = INT_MIN, current_max = 0;
    int start_index = 0, end_index = 0, j = 0;

    for (int i = 0; i < n; i++) {
        current_max += arr[i];

        if (current_max > max_so_far) {
            max_so_far = current_max;
            start_index = j;
            end_index = i;
        }

        if (current_max < 0) {
            current_max = 0;
            j = i + 1;
        }
    }

    printf("Maximum contiguous subarray: [");
    for (int i = start_index; i <= end_index; i++) {
        printf("%d", arr[i]);
        if (i < end_index) {
            printf(", ");
        }
    }
    printf("]
");
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    max_subarray_sum(arr, n);
    return 0;
}