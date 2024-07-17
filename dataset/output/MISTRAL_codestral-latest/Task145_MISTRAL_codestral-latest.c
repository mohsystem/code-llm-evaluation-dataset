#include <stdio.h>

int maxSubArraySum(int arr[], int n) {
    int maxSoFar = arr[0];
    int currMax = arr[0];

    for (int i = 1; i < n; i++) {
        currMax = (arr[i] > currMax + arr[i]) ? arr[i] : currMax + arr[i];
        maxSoFar = (maxSoFar > currMax) ? maxSoFar : currMax;
    }

    return maxSoFar;
}