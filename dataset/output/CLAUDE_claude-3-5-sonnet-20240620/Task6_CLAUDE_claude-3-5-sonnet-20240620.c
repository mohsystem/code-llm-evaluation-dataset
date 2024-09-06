
#include <stdio.h>

double findUniq(const double *arr, size_t n) {
    if (arr[0] != arr[1] && arr[0] != arr[2]) return arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] != arr[0]) return arr[i];
    }
    return arr[0];  // This line should never be reached given the problem constraints
}

int main() {
    double arr1[] = {1, 1, 1, 2, 1, 1};
    double arr2[] = {0, 0, 0.55, 0, 0};
    
    printf("%f\\n", findUniq(arr1, 6));  // Output: 2.000000
    printf("%f\\n", findUniq(arr2, 5));  // Output: 0.550000
    
    return 0;
}
