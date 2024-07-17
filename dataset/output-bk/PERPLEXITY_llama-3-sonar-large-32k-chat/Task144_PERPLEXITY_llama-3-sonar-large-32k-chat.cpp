#include <iostream>
#include <algorithm>

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int merged[8];
    for (int i = 0; i < 4; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < 4; i++) {
        merged[i + 4] = arr2[i];
    }
    std::sort(merged, merged + 8);
    for (int i = 0; i < 8; i++) {
        std::cout << merged[i] << " ";
    }
    return 0;
}