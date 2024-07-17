#include <iostream>
#include <vector>
#include <string>

std::string createPhoneNumber(const std::vector<int>& numbers);

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << createPhoneNumber(numbers) << std::endl;
    return 0;
}

std::string createPhoneNumber(const std::vector<int>& numbers) {
    return "(" + std::to_string(numbers[0]) + std::to_string(numbers[1]) + std::to_string(numbers[2]) + ") " +
           std::to_string(numbers[3]) + std::to_string(numbers[4]) + std::to_string(numbers[5]) + "-" +
           std::to_string(numbers[6]) + std::to_string(numbers[7]) + std::to_string(numbers[8]) + std::to_string(numbers[9]);
}