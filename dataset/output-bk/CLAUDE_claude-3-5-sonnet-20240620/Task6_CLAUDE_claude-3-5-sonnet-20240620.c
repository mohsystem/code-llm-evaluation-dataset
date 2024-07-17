
#include <stdio.h>

double findUniq(const double *arr, size_t n) {
    if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
    if (arr[1] != arr[0] && arr[1] != arr[2]) return arr[1];
    
    for (size_t i = 2; i < n; i++) {
        if (arr[i] != arr[0]) return arr[i];
    }
    
    return arr[0];
}

int main() {
    double arr1[] = { 1, 1, 1, 2, 1, 1 };
    double arr2[] = { 0, 0, 0.55, 0, 0 };
    
    printf("%f\
", findUniq(arr1, sizeof(arr1)/sizeof(arr1[0])));
    printf("%f\
", findUniq(arr2, sizeof(arr2)/sizeof(arr2[0])));
    
    return 0;
}
