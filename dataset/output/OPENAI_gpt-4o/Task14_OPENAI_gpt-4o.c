#include <stdio.h>

int findEvenIndex(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        int leftSum = 0, rightSum = 0;
        for (int l = 0; l < i; l++) leftSum += arr[l];
        for (int r = i + 1; r < length; r++) rightSum += arr[r];
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 3, 2, 1};
    int arr2[] = {1, 100, 50, -51, 1, 1};
    int arr3[] = {20, 10, -80, 10, 10, 15, 35};
    
    printf("%d\n", findEvenIndex(arr1, 7));  // Output should be 3
    printf("%d\n", findEvenIndex(arr2, 6));  // Output should be 1
    printf("%d\n", findEvenIndex(arr3, 7));  // Output should be 0
    
    return 0;
}