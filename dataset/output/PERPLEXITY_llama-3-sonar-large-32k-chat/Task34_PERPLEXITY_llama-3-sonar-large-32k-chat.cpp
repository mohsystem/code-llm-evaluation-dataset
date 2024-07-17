#include <cmath>
#include <iostream>

bool isNarcissistic(int n) {
    int sum = 0, temp = n;
    int digits = 0;
    for (int i = n; i != 0; i /= 10) {
        digits++;
    }
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    std::cout << std::boolalpha << isNarcissistic(153) << std::endl; // true
    std::cout << std::boolalpha << isNarcissistic(1652) << std::endl; // false
    return 0;
}