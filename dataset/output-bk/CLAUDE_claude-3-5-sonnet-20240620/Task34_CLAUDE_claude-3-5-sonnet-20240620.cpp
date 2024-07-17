
#include <iostream>
#include <cmath>
#include <string>

bool isNarcissistic(int number) {
    std::string numStr = std::to_string(number);
    int length = numStr.length();
    int sum = 0;

    for (char digit : numStr) {
        sum += std::pow(digit - \'0\', length);
    }

    return sum == number;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isNarcissistic(153) << std::endl;  // true
    std::cout << isNarcissistic(1652) << std::endl; // false
    return 0;
}
