#include <stdio.h>
#include <stdlib.h>

int *merge_sorted_arrays(int arr1[], int size1, int arr2[], int size2) {
    int *merged_array = malloc(sizeof(int) * (size1 + size2));
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged_array[k++] = arr1[i++];
        } else {
            merged_array[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        merged_array[k++] = arr1[i++];
    }
    while (j < size2) {
        merged_array[k++] = arr2[j++];
    }
    return merged_array;
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int *merged_array = merge_sorted_arrays(arr1, size1, arr2, size2);

    printf("Merged Array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged_array[i]);
    }
    printf("\n");

    free(merged_array);
    return 0;
}