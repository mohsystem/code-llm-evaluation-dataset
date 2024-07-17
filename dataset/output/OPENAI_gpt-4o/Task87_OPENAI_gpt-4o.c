#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    // if we reach here, then element was not present
    return -1;
}

int main() {
    FILE *fp;
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    clock_t start, end;

    start = clock();
    int result = binarySearch(arr, 0, n - 1, x);
    end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    fp = fopen("execution_time.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!
");
        return 1;
    }
    fprintf(fp, "Execution time in seconds: %f
", cpu_time_used);
    fclose(fp);

    if(result == -1)
        printf("Element not present
");
    else
        printf("Element found at index %d
", result);

    return 0;
}