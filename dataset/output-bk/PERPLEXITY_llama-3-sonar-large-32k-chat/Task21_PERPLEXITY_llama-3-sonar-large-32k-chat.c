#include <stdio.h>

void removeSmallest(int arr[], int n) {
    if (n == 0) return;
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    for (int i = minIndex; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("
");
}

int main() {
    int arr[] = {5, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    removeSmallest(arr, n);
    return 0;
}