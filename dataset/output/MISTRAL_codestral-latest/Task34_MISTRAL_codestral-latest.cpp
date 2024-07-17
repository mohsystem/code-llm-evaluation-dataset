#include <iostream>
#include <cmath>

bool isNarcissistic(int number) {
    int originalNumber, result = 0, remainder;
    int n = std::to_string(number).length();

    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += std::pow(remainder, n);
        originalNumber /= 10;
    }

    return number == result;
}