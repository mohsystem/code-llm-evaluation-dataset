#include <iostream>

double findUniq(double arr[], int size) {
    double a = arr[0];
    double b = arr[1];
    if (a == b) {
        for (int i = 2; i < size; i++) {
            if (arr[i] != a) return arr[i];
        }
    } else {
        for (int i = 2; i < size; i++) {
            if (arr[i] == a) return b;
            if (arr[i] == b) return a;
        }
    }
    return -1; // not found
}

int main() {
    double arr[] = {1, 1, 1, 2, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << findUniq(arr, size) << std::endl;
    return 0;
}