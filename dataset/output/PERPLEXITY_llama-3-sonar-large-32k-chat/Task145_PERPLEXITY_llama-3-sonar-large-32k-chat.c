#include <stdio.h>

int maxSubArraySum(int arr[], int n) {
    int maxCurrent = maxGlobal = arr[0];
    for (int i = 1; i < n; i++) {
        maxCurrent = (arr[i] > maxCurrent + arr[i]) ? arr[i] : maxCurrent + arr[i];
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements separated by space: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Maximum contiguous sum is %d\n", maxSubArraySum(arr, n));
    return 0;
}