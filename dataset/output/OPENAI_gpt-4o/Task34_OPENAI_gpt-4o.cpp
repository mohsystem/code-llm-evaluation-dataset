// C++ Code
#include <iostream>
#include <cmath>

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

bool isNarcissistic(int number) {
    int originalNumber = number;
    int sum = 0;
    int numberOfDigits = countDigits(number);
    while (number > 0) {
        int digit = number % 10;
        sum += pow(digit, numberOfDigits);
        number /= 10;
    }
    return sum == originalNumber;
}

int main() {
    int num = 153; // example number
    std::cout << std::boolalpha << isNarcissistic(num) << std::endl;
    return 0;
}