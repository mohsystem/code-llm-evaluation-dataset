#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int merged[8];
    int i, j, k;
    for (i = 0; i < 4; i++) {
        merged[i] = arr1[i];
    }
    for (j = 0; j < 4; j++) {
        merged[i + j] = arr2[j];
    }
    for (i = 0; i < 8; i++) {
        for (j = i + 1; j < 8; j++) {
            if (merged[i] > merged[j]) {
                int temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }
    for (k = 0; k < 8; k++) {
        printf("%d ", merged[k]);
    }
    return 0;
}