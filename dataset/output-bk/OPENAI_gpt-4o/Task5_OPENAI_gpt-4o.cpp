#include <iostream>

int multiplyDigits(int num) {
    int product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

int persistence(int num) {
    int count = 0;
    while (num >= 10) {
        num = multiplyDigits(num);
        count++;
    }
    return count;
}

int main() {
    std::cout << persistence(39) << std::endl; // should return 3
    std::cout << persistence(999) << std::endl; // should return 4
    std::cout << persistence(4) << std::endl; // should return 0
    return 0;
}