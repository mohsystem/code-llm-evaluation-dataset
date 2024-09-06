
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int longestRun(const std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    
    int maxRun = 1;
    int currentRun = 1;
    
    for (size_t i = 1; i < arr.size(); ++i) {
        if (std::abs(arr[i] - arr[i-1]) == 1) {
            currentRun++;
            maxRun = std::max(maxRun, currentRun);
        } else {
            currentRun = 1;
        }
    }
    
    return maxRun;
}

int main() {
    std::cout << longestRun({1, 2, 3, 5, 6, 7, 8, 9}) << std::endl;  // Output: 5
    std::cout << longestRun({1, 2, 3, 10, 11, 15}) << std::endl;     // Output: 3
    std::cout << longestRun({5, 4, 2, 1}) << std::endl;              // Output: 2
    std::cout << longestRun({3, 5, 7, 10, 15}) << std::endl;         // Output: 1
    return 0;
}
