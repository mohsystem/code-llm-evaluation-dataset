
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    clock_t start = clock();
    int result = binarySearch(arr, 0, n - 1, target);
    clock_t end = clock();

    double executionTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    FILE *tempFile = tmpfile();
    if (tempFile != NULL) {
        fprintf(tempFile, "Execution time: %f seconds", executionTime);
        fseek(tempFile, 0, SEEK_SET);
        char buffer[100];
        fgets(buffer, sizeof(buffer), tempFile);
        printf("Execution time written to temporary file: %s\
", buffer);
        fclose(tempFile);
    } else {
        printf("Failed to create temporary file\
");
    }

    if (result != -1)
        printf("Element found at index: %d\
", result);
    else
        printf("Element not found\
");

    return 0;
}
