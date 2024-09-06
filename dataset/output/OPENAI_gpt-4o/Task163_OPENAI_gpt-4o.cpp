#include <iostream>
#include <vector>

int longestRun(const std::vector<int>& lst) {
    if (lst.empty()) {
        return 0;
    }
    int maxRun = 1;
    int currentRun = 1;
    for (size_t i = 1; i < lst.size(); ++i) {
        if (lst[i] == lst[i-1] + 1 || lst[i] == lst[i-1] - 1) {
            currentRun += 1;
        } else {
            maxRun = std::max(maxRun, currentRun);
            currentRun = 1;
        }
    }
    return std::max(maxRun, currentRun);
}

int main() {
    std::cout << longestRun({1, 2, 3, 5, 6, 7, 8, 9}) << std::endl;
    std::cout << longestRun({1, 2, 3, 10, 11, 15}) << std::endl;
    std::cout << longestRun({5, 4, 2, 1}) << std::endl;
    std::cout << longestRun({3, 5, 7, 10, 15}) << std::endl;
}