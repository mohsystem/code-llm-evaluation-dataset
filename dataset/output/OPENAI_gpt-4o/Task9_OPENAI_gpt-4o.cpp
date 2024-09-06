#include <iostream>
#include <vector>

std::string sumIsOddOrEven(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum % 2 == 0 ? "even" : "odd";
}

int main() {
    std::cout << sumIsOddOrEven({0}) << std::endl;        // even
    std::cout << sumIsOddOrEven({0, 1, 4}) << std::endl;  // odd
    std::cout << sumIsOddOrEven({0, -1, -5}) << std::endl; // even
    return 0;
}