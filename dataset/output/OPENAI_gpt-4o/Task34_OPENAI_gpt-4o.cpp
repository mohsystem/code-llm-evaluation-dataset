#include <iostream>
#include <cmath>
#include <string>

bool isNarcissistic(int number) {
    std::string numStr = std::to_string(number);
    int power = numStr.length();
    int sum = 0;

    for (char c : numStr) {
        int digit = c - '0';
        sum += std::pow(digit, power);
    }

    return sum == number;
}

int main() {
    std::cout << isNarcissistic(153) << std::endl;  // 1 (true)
    std::cout << isNarcissistic(1652) << std::endl;  // 0 (false)
    return 0;
}