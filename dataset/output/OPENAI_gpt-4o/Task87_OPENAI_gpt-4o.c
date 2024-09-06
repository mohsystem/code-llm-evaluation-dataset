#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main(void) {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    clock_t start = clock();
    int result = binarySearch(arr, 0, n - 1, x);
    clock_t end = clock();
    double execution_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    FILE *tempFile = fopen("binary_search_execution_time.txt", "w");
    if (tempFile != NULL) {
        fprintf(tempFile, "Execution time: %f seconds", execution_time);
        fclose(tempFile);
    }

    return 0;
}