#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void posNegSort(int arr[], int n) {
    int pos[n], pos_i = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos[pos_i++] = arr[i];
        }
    }
    bubbleSort(pos, pos_i);
    pos_i = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = pos[pos_i++];
        }
    }
}