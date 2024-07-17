#include <stdio.h>

int findMissingNumber(int array[], int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < n - 1; ++i) {
        actualSum += array[i];
    }
    return expectedSum - actualSum;
}

int main() {
    int array[] = {1, 2, 4, 5, 6};  // Input your array here
    int n = (sizeof(array) / sizeof(array[0])) + 1;
    printf("Missing number is: %d
", findMissingNumber(array, n));
    return 0;
}