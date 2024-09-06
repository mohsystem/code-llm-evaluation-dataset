#include <iostream>
#include <vector>

int binaryArrayToInt(const std::vector<int>& arr) {
    int result = 0;
    for (int bit : arr) {
        result = (result << 1) | bit;
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> test_cases = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1}
    };

    for (const auto& arr : test_cases) {
        std::cout << "Testing: [ ";
        for (int bit : arr) {
            std::cout << bit << " ";
        }
        std::cout << "] ==> " << binaryArrayToInt(arr) << std::endl;
    }

    return 0;
}