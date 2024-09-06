#include <stdio.h>

double findUniq(double arr[], int size) {
    double a = arr[0], b = arr[1];
    for(int i = 0; i < size; i++) {
        if(arr[i] != a) {
            if(arr[i] != b) return arr[i];
            return a;
        } else if(b != a) return b;
        b = arr[i];
    }
    return a;
}

int main() {
    double arr1[] = { 1, 1, 1, 2, 1, 1 };
    double arr2[] = { 0, 0, 0.55, 0, 0 };
    printf("%f\n", findUniq(arr1, 6)); // => 2
    printf("%f\n", findUniq(arr2, 5)); // => 0.55
    return 0;
}