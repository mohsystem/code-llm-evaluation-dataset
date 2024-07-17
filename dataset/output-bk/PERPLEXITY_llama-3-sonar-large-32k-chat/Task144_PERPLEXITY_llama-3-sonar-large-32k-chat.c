#include <stdio.h>

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int merged[8];
    int i;
    for (i = 0; i < 4; i++) {
        merged[i] = arr1[i];
    }
    for (i = 0; i < 4; i++) {
        merged[i + 4] = arr2[i];
    }
    for (i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (merged[i] > merged[j]) {
                int temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        printf("%d ", merged[i]);
    }
    return 0;
}