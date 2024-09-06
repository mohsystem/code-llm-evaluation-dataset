#include <stdio.h>

int maxSubArraySum(int arr[], int size) {
    int maxCurrent = arr[0];
    int maxGlobal = arr[0];

    for (int i = 1; i < size; i++) {
        maxCurrent = arr[i] > (maxCurrent + arr[i]) ? arr[i] : (maxCurrent + arr[i]);
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}

int main() {
    int arr[] = {1, -3, 2, 1, -1};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Max contiguous subarray sum is: %d\n", maxSubArraySum(arr, size));
    return 0;
}