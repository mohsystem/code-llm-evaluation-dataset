
#include <stdlib.h>

int* filter_list(int* arr, int n, int* newSize) {
    int* result = malloc(n * sizeof(int));
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            result[count++] = arr[i];
        }
    }
    
    *newSize = count;
    return result;
}
