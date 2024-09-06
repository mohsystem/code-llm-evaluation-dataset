
#include <iostream>
#include <vector>

int findOdd(const std::vector<int>& arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;
    }
    return result;
}

int main() {
    std::cout << findOdd({7}) << std::endl;
    std::cout << findOdd({0}) << std::endl;
    std::cout << findOdd({1,1,2}) << std::endl;
    std::cout << findOdd({0,1,0,1,0}) << std::endl;
    std::cout << findOdd({1,2,2,3,3,3,4,3,3,3,2,2,1}) << std::endl;
    return 0;
}
