
#include <iostream>
#include <string>
#include <cmath>

class DigPow {
public:
    static long long digPow(int n, int p) {
        std::string digits = std::to_string(n);
        long long sum = 0;
        for (size_t i = 0; i < digits.length(); i++) {
            int digit = digits[i] - \'0\';
            sum += std::pow(digit, p + i);
        }
        if (sum % n == 0) {
            return sum / n;
        }
        return -1;
    }
};

int main() {
    std::cout << DigPow::digPow(89, 1) << std::endl;
    std::cout << DigPow::digPow(92, 1) << std::endl;
    std::cout << DigPow::digPow(695, 2) << std::endl;
    std::cout << DigPow::digPow(46288, 3) << std::endl;
    return 0;
}
