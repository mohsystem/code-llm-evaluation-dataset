#include <iostream>
#include <cmath>
#include <string>

int digPow(int n, int p) {
    std::string numStr = std::to_string(n);
    int sum = 0;
    for (size_t i = 0; i < numStr.length(); i++) {
        sum += std::pow(numStr[i] - '0', p + i);
    }
    if (sum % n == 0) {
        return sum / n;
    } else {
        return -1;
    }
}

int main() {
    std::cout << digPow(89, 1) << std::endl;       // Output: 1
    std::cout << digPow(92, 1) << std::endl;       // Output: -1
    std::cout << digPow(695, 2) << std::endl;      // Output: 2
    std::cout << digPow(46288, 3) << std::endl;    // Output: 51
    return 0;
}