#include <stdio.h>

void posNegSort(int arr[], int n) {
    int pos[100];
    int pos_index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            pos[pos_index] = arr[i];
            pos_index++;
        }
    }
    for (int i = 0; i < pos_index - 1; i++) {
        for (int j = i + 1; j < pos_index; j++) {
            if (pos[i] > pos[j]) {
                int temp = pos[i];
                pos[i] = pos[j];
                pos[j] = temp;
            }
        }
    }
    pos_index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] = pos[pos_index];
            pos_index++;
        }
    }
}