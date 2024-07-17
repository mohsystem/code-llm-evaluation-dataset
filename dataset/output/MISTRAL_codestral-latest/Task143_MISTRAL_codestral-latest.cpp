#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    return 0;
}