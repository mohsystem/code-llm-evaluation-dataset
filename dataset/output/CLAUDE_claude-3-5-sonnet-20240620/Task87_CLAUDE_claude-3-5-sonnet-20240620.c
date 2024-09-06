
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    clock_t start_time = clock();
    int result = binary_search(arr, 0, n - 1, target);
    clock_t end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    char temp_filename[] = "execution_time_XXXXXX";
    int fd = mkstemp(temp_filename);
    if (fd != -1) {
        FILE* temp_file = fdopen(fd, "w");
        if (temp_file != NULL) {
            fprintf(temp_file, "Execution time: %.6f seconds", execution_time);
            fclose(temp_file);
            printf("Execution time written to: %s\\n", temp_filename);
        }
    }

    printf("Result: %d\\n", result);

    return 0;
}
