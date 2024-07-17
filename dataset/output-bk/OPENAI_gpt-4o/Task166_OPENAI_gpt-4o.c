#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

void posNegSort(int arr[], int size) {
    int *pos_numbers = (int *)malloc(size * sizeof(int));
    int pos_cnt = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            pos_numbers[pos_cnt++] = arr[i];
        }
    }
    qsort(pos_numbers, pos_cnt, sizeof(int), cmpfunc);
    
    int pos_idx = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            arr[i] = pos_numbers[pos_idx++];
        }
    }
    
    free(pos_numbers);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("
");
}

int main() {
    int arr1[] = {6, 3, -2, 5, -8, 2, -2};
    posNegSort(arr1, 7);
    printArray(arr1, 7);  // ➞ [2, 3, -2, 5, -8, 6, -2]

    int arr2[] = {6, 5, 4, -1, 3, 2, -1, 1};
    posNegSort(arr2, 8);
    printArray(arr2, 8);  // ➞ [1, 2, 3, -1, 4, 5, -1, 6]

    int arr3[] = {-5, -5, -5, -5, 7, -5};
    posNegSort(arr3, 6);
    printArray(arr3, 6);  // ➞ [-5, -5, -5, -5, 7, -5]

    int arr4[] = {};
    posNegSort(arr4, 0);
    printArray(arr4, 0);  // ➞ []

    return 0;
}