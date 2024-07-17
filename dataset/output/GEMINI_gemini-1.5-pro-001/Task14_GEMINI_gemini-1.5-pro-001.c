#include <stdio.h>

int findEvenIndex(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int leftSum = 0;
        int rightSum = 0;
        for (int j = 0; j < i; j++) {
            leftSum += arr[j];
        }
        for (int j = i + 1; j < n; j++) {
            rightSum += arr[j];
        }
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = findEvenIndex(arr, n);
    printf("%d
", result); // Output: 3
    return 0;
}