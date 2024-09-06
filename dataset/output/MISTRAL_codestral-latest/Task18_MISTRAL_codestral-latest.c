#include <stdio.h>

int binaryArrayToNumber(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = (result << 1) | arr[i];
    }
    return result;
}