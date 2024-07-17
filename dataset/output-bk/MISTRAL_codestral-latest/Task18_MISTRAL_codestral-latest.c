#include <stdio.h>
#include <math.h>

int binaryArrayToNumber(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = result * 2 + arr[i];
    }
    return result;
}