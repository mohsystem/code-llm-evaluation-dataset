#include <iostream>
#include <vector>

std::string oddOrEven(const std::vector<int>& list) {
    int sum = 0;
    for(int num : list) {
        sum += num;
    }
    return (sum % 2 == 0) ? "even" : "odd";
}

int main() {
    std::vector<int> list = {0, -1, -5}; // Example input list
    std::cout << oddOrEven(list) << std::endl;
    return 0;
}