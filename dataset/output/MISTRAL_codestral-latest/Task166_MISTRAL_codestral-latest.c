#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void posNegSort(int arr[], int n) {
    int pos[n], neg[n], pos_count = 0, neg_count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos[pos_count++] = arr[i];
        } else {
            neg[neg_count++] = arr[i];
        }
    }

    bubbleSort(pos, pos_count);

    int pos_index = 0, neg_index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = pos[pos_index++];
        } else {
            arr[i] = neg[neg_index++];
        }
    }
}

int main() {
    int arr[] = {6, 3, -2, 5, -8, 2, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    posNegSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}