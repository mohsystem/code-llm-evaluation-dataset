
#include <iostream>
#include <vector>

class BinaryArrayToNumber {
public:
    static int convertBinaryArrayToInt(std::vector<int> binary) {
        return std::accumulate(binary.begin(), binary.end(), 0, [](int result, int bit) {
            return result * 2 + bit;
        });
    }
};

int main() {
    std::cout << BinaryArrayToNumber::convertBinaryArrayToInt({0, 0, 0, 1}) << std::endl; // 1
    std::cout << BinaryArrayToNumber::convertBinaryArrayToInt({0, 0, 1, 0}) << std::endl; // 2
    std::cout << BinaryArrayToNumber::convertBinaryArrayToInt({0, 1, 0, 1}) << std::endl; // 5
    std::cout << BinaryArrayToNumber::convertBinaryArrayToInt({1, 0, 0, 1}) << std::endl; // 9
    std::cout << BinaryArrayToNumber::convertBinaryArrayToInt({0, 1, 1, 0}) << std::endl; // 6
    std::cout << BinaryArrayToNumber::convertBinaryArrayToInt({1, 1, 1, 1}) << std::endl; // 15
    std::cout << BinaryArrayToNumber::convertBinaryArrayToInt({1, 0, 1, 1}) << std::endl; // 11

    return 0;
}
