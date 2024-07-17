
#include <iostream>

int persistence(long long n) {
    if (n < 10) return 0;
    int count = 0;
    while (n >= 10) {
        long long product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        n = product;
        count++;
    }
    return count;
}

int main() {
    std::cout << persistence(39) << std::endl;  // Output: 3
    std::cout << persistence(999) << std::endl; // Output: 4
    std::cout << persistence(4) << std::endl;   // Output: 0
    return 0;
}
