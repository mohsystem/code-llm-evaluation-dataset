#include <stdio.h>

int findEvenIndex(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int leftSum = 0;
        int rightSum = 0;
        for (int j = 0; j < i; j++) {
            leftSum += arr[j];
        }
        for (int j = i + 1; j < size; j++) {
            rightSum += arr[j];
        }
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", findEvenIndex(arr, size));
    return 0;
}