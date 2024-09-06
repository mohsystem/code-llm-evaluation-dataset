
#include <stdio.h>

int findMissingNumber(int arr[], int size) {
    int n = size + 1;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}

int main() {
    int inputArray[] = {1, 2, 4, 6, 3, 7, 8};
    int size = sizeof(inputArray) / sizeof(inputArray[0]);
    int missingNumber = findMissingNumber(inputArray, size);
    printf("The missing number is: %d\\n", missingNumber);
    return 0;
}
