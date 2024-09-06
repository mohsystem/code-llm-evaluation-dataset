#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged(arr1.begin(), arr1.end());
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    std::sort(merged.begin(), merged.end());
    return merged;
}

int main() {
    std::vector<int> arr1 = {1, 3, 5, 7};
    std::vector<int> arr2 = {2, 4, 6, 8};
    std::vector<int> merged = mergeArrays(arr1, arr2);
    std::cout << "Merged array in C++: ";
    for (int num : merged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}