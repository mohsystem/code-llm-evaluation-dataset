#include <iostream>

int persistence(long n) {
    int count = 0;
    while (n >= 10) {
        long mult = 1;
        while (n > 0) {
            mult *= n % 10;
            n /= 10;
        }
        n = mult;
        count++;
    }
    return count;
}

int main() {
    std::cout << persistence(39) << std::endl;  // 3
    std::cout << persistence(999) << std::endl; // 4
    std::cout << persistence(4) << std::endl;   // 0
    return 0;
}