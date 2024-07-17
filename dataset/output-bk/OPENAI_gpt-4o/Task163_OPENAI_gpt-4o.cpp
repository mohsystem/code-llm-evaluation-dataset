#include <iostream>
#include <vector>
#include <algorithm>

int longestRun(std::vector<int> arr) {
    if (arr.empty()) {
        return 0;
    }

    int maxLength = 1;
    int currentLength = 1;

    // Check for increasing consecutive runs
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currentLength += 1;
        } else {
            maxLength = std::max(maxLength, currentLength);
            currentLength = 1;
        }
    }
    maxLength = std::max(maxLength, currentLength);

    currentLength = 1;

    // Check for decreasing consecutive runs
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1] - 1) {
            currentLength += 1;
        } else {
            maxLength = std::max(maxLength, currentLength);
            currentLength = 1;
        }
    }
    maxLength = std::max(maxLength, currentLength);

    return maxLength;
}

int main() {
    std::cout << longestRun({1, 2, 3, 5, 6, 7, 8, 9}) << std::endl; // ➞ 5
    std::cout << longestRun({1, 2, 3, 10, 11, 15}) << std::endl; // ➞ 3
    std::cout << longestRun({5, 4, 2, 1}) << std::endl; // ➞ 2
    std::cout << longestRun({3, 5, 7, 10, 15}) << std::endl; // ➞ 1
}