#include <stdio.h>
#include <stdlib.h>

void posNegSort(int* lst, int size, int* result) {
    int* pos_nums = (int*)malloc(size * sizeof(int));
    int pos_index = 0, result_index = 0;
    
    for (int i = 0; i < size; ++i) {
        if (lst[i] > 0) pos_nums[pos_index++] = lst[i];
    }
    
    qsort(pos_nums, pos_index, sizeof(int), (int(*)(const void*, const void*)) strcmp);
    
    pos_index = 0;
    for (int i = 0; i < size; ++i) {
        if (lst[i] > 0) {
            result[result_index++] = pos_nums[pos_index++];
        } else {
            result[result_index++] = lst[i];
        }
    }
    free(pos_nums);
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int lst1[] = {6, 3, -2, 5, -8, 2, -2};
    int result1[7];
    posNegSort(lst1, 7, result1);
    printArray(result1, 7);  // [2, 3, -2, 5, -8, 6, -2]
    
    int lst2[] = {6, 5, 4, -1, 3, 2, -1, 1};
    int result2[8];
    posNegSort(lst2, 8, result2);
    printArray(result2, 8);  // [1, 2, 3, -1, 4, 5, -1, 6]
    
    int lst3[] = {-5, -5, -5, -5, 7, -5};
    int result3[6];
    posNegSort(lst3, 6, result3);
    printArray(result3, 6);  // [-5, -5, -5, -5, 7, -5]
    
    int lst4[] = {};
    int result4[0];
    posNegSort(lst4, 0, result4);
    //printArray(result4, 0);  // []
    
    return 0;
}