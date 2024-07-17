// C++ code
#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n);
    std::cout << "Sorted array is: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}