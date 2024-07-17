#include <iostream>
#include <vector>

int convertBinaryArrayToInt(const std::vector<int>& binaryArray) {
    int result = 0;
    for (int bit : binaryArray) {
        result = result * 2 + bit;
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1}
    };

    for (const auto& testCase : testCases) {
        std::cout << convertBinaryArrayToInt(testCase) << std::endl;
    }

    return 0;
}