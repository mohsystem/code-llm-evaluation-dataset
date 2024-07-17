#include <stdio.h>

int find_even_index(int arr[], int n) {
    int left_sum, right_sum;
    for (int i = 0; i < n; i++) {
        left_sum = 0;
        right_sum = 0;
        for (int j = 0; j < i; j++) {
            left_sum += arr[j];
        }
        for (int j = i + 1; j < n; j++) {
            right_sum += arr[j];
        }
        if (left_sum == right_sum) {
            return i;
        }
    }
    return -1;
}