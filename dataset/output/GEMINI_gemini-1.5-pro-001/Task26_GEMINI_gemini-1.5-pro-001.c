#include <stdio.h>
#include <stdlib.h>

int findOdd(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr1[] = {7};
    int arr2[] = {0};
    int arr3[] = {1, 1, 2};
    int arr4[] = {0, 1, 0, 1, 0};
    int arr5[] = {1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    printf("%d
", findOdd(arr1, n1));
    printf("%d
", findOdd(arr2, n2));
    printf("%d
", findOdd(arr3, n3));
    printf("%d
", findOdd(arr4, n4));
    printf("%d
", findOdd(arr5, n5));

    return 0;
}