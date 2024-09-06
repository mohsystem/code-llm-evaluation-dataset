#include <stdio.h>
#include <stdlib.h>
int find_even_index(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int leftSum = 0;
        for (int j = 0; j < i; j++) {
            leftSum += arr[j];
        }
        int rightSum = 0;
        for (int j = i + 1; j < n; j++) {
            rightSum += arr[j];
        }
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}