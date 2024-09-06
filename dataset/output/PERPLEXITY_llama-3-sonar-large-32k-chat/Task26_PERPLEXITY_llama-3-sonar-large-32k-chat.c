#include <stdio.h>

int findOdd(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count % 2 != 0) {
            return arr[i];
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,2,3,3,3,4,3,3,3,2,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", findOdd(arr, size));
    return 0;
}