#include <iostream>
#include <vector>
#include <algorithm>

void removeSmallest(std::vector<int>& arr) {
    if (arr.empty()) return;
    auto it = std::min_element(arr.begin(), arr.end());
    arr.erase(it);
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {5, 3, 2, 1, 4};
    removeSmallest(arr);
    return 0;
}