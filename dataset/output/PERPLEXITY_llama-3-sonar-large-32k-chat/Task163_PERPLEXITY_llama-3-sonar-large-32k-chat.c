#include <stdio.h>
#include <stdlib.h>

int longestRun(int* arr, int size) {
    if (size == 0) {
        return 0;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int longest_run = 1;
    int current_run = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] - arr[i-1] == 1) {
            current_run += 1;
        } else {
            longest_run = (longest_run > current_run) ? longest_run : current_run;
            current_run = 1;
        }
    }
    return (longest_run > current_run) ? longest_run : current_run;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d
", longestRun(arr, size));
    return 0;
}