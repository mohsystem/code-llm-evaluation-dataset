#include <stdio.h>
#include <stdlib.h>

void mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int* mergedArray) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }
    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int* mergedArray = (int*)malloc((size1 + size2) * sizeof(int));
    
    mergeSortedArrays(arr1, size1, arr2, size2, mergedArray);
    
    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("
");
    
    free(mergedArray);
    return 0;
}