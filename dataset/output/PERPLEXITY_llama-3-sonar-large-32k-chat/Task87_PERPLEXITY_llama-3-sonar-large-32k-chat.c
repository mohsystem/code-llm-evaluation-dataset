#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int target, int left, int right) {
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
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    clock_t start = clock();
    int result = binarySearch(arr, target, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    clock_t end = clock();
    double timeElapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    FILE *fp = fopen("execution_time.txt", "w");
    fprintf(fp, "Execution time: %f milliseconds
", timeElapsed);
    fclose(fp);
    printf("Element found at index %d
", result);
    return 0;
}