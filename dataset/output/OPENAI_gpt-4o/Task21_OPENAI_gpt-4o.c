#include <stdio.h>
#include <limits.h>

void remove_smallest(int* numbers, int size, int* result, int* result_size) {
    if (size == 0) {
        *result_size = 0;
        return;
    }
    
    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (numbers[i] < numbers[min_index]) {
            min_index = i;
        }
    }
    
    for (int i = 0, j = 0; i < size; i++) {
        if(i != min_index) {
            result[j++] = numbers[i];
        }
    }
    *result_size = size - 1;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 3, 2, 1, 4};
    int arr3[] = {2, 2, 1, 2, 1};
    
    int result1[5], result2[5], result3[5];
    int result_size1, result_size2, result_size3;
    
    remove_smallest(arr1, 5, result1, &result_size1);
    remove_smallest(arr2, 5, result2, &result_size2);
    remove_smallest(arr3, 5, result3, &result_size3);
    
    for (int i = 0; i < result_size1; i++) printf("%d ", result1[i]);
    printf("\n");
    for (int i = 0; i < result_size2; i++) printf("%d ", result2[i]);
    printf("\n");
    for (int i = 0; i < result_size3; i++) printf("%d ", result3[i]);
    printf("\n");
    
    return 0;
}