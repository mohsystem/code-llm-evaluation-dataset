#include <iostream>
#include <numeric>
#include <vector>

int findEvenIndex(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        int leftSum = std::accumulate(arr.begin(), arr.begin() + i, 0);
        int rightSum = std::accumulate(arr.begin() + i + 1, arr.end(), 0);
        if (leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::cout << findEvenIndex({1, 2, 3, 4, 3, 2, 1}) << std::endl;  // Output should be 3
    std::cout << findEvenIndex({1, 100, 50, -51, 1, 1}) << std::endl;  // Output should be 1
    std::cout << findEvenIndex({20, 10, -80, 10, 10, 15, 35}) << std::endl;  // Output should be 0
    return 0;
}