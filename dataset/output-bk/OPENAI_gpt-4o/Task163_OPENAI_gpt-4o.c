#include <stdio.h>
#include <stdlib.h>

int longestRun(int* arr, int size) {
    if (size == 0) {
        return 0;
    }

    int maxLength = 1;
    int currentLength = 1;

    // Check for increasing consecutive runs
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currentLength += 1;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    currentLength = 1;

    // Check for decreasing consecutive runs
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1] - 1) {
            currentLength += 1;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength;
}

int main() {
    int arr1[] = {1, 2, 3, 5, 6, 7, 8, 9};
    int arr2[] = {1, 2, 3, 10, 11, 15};
    int arr3[] = {5, 4, 2, 1};
    int arr4[] = {3, 5, 7, 10, 15};

    printf("%d
", longestRun(arr1, 8)); // ➞ 5
    printf("%d
", longestRun(arr2, 6)); // ➞ 3
    printf("%d
", longestRun(arr3, 4)); // ➞ 2
    printf("%d
", longestRun(arr4, 5)); // ➞ 1

    return 0;
}