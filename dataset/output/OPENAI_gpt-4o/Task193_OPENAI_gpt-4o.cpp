#include <iostream>
#include <vector>

bool xorGame(std::vector<int>& nums) {
    int xorValue = 0;
    for (int num : nums) {
        xorValue ^= num;
    }
    return xorValue == 0 || nums.size() % 2 == 0;
}

int main() {
    std::cout << xorGame(std::vector<int>{1, 1, 2}) << std::endl;  // Output: 0 (false)
    std::cout << xorGame(std::vector<int>{0, 1}) << std::endl;    // Output: 1 (true)
    std::cout << xorGame(std::vector<int>{1, 2, 3}) << std::endl; // Output: 1 (true)
    return 0;
}