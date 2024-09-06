#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int binarySearch(int arr[], int target, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 101;
    }
    for (int i = 0; i < 10000; i++) {
        for (int j = i + 1; j < 10000; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    clock_t start_time = clock();
    int index = binarySearch(arr, 50, 0, 9999);
    clock_t end_time = clock();

    FILE *file = fopen("temp.txt", "w");
    fprintf(file, "Execution time: %.6f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    if (index != -1) {
        fprintf(file, "Target found at index %d\n", index);
    } else {
        fprintf(file, "Target not found\n");
    }
    fclose(file);
    return 0;
}