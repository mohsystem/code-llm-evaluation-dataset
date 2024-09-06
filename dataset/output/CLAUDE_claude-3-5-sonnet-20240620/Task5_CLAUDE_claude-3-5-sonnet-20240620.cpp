
#include <iostream>

int persistence(long long num) {
    if (num < 10) {
        return 0;
    }
    
    long long product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    
    return 1 + persistence(product);
}

int main() {
    std::cout << persistence(39) << std::endl;  // Output: 3
    std::cout << persistence(999) << std::endl; // Output: 4
    std::cout << persistence(4) << std::endl;   // Output: 0
    return 0;
}
