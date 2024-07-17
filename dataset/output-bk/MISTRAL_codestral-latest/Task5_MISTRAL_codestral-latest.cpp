#include <iostream>

int persistence(int num) {
    int count = 0;
    while (num >= 10) {
        int product = 1;
        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }
        num = product;
        count++;
    }
    return count;
}

int main() {
    std::cout << persistence(39) << std::endl; // Output: 3
    std::cout << persistence(999) << std::endl; // Output: 4
    std::cout << persistence(4) << std::endl; // Output: 0
    return 0;
}