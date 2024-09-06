
#include <iostream>
#include <vector>
#include <string>

int convertBinaryArrayToInt(const std::vector<int>& binary) {
    std::string binaryString;
    for (int digit : binary) {
        binaryString += std::to_string(digit);
    }
    return std::stoi(binaryString, nullptr, 2);
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
        std::cout << "Testing: [";
        for (size_t i = 0; i < testCase.size(); ++i) {
            std::cout << testCase[i];
            if (i < testCase.size() - 1) std::cout << ", ";
        }
        std::cout << "] ==> " << convertBinaryArrayToInt(testCase) << std::endl;
    }

    return 0;
}
