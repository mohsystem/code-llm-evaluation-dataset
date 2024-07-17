#include <stdio.h>

int find_outlier(int* arr, int n) {
    int even = 0, odd = 0;
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even = arr[i];
            even_count++;
        } else {
            odd = arr[i];
            odd_count++;
        }
    }

    return (even_count < odd_count) ? even : odd;
}