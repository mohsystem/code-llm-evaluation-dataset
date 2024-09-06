
#include <iostream>
#include <vector>
#include <numeric>

std::string oddOrEven(const std::vector<int>& arr) {
    return std::accumulate(arr.begin(), arr.end(), 0) % 2 == 0 ? "even" : "odd";
}

int main() {
    std::cout << oddOrEven({0}) << std::endl;  // Output: "even"
    std::cout << oddOrEven({0, 1, 4}) << std::endl;  // Output: "odd"
    std::cout << oddOrEven({0, -1, -5}) << std::endl;  // Output: "even"
    return 0;
}
