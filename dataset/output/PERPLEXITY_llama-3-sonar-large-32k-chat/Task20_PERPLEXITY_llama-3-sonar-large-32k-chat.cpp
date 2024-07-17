#include <iostream>
#include <cmath>

int digitPowerSum(int n, int p) {
    int sum = 0;
    int temp = n;
    int i = 0;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, p + i);
        temp /= 10;
        i++;
    }
    if (sum % n == 0) {
        return sum / n;
    } else {
        return -1;
    }
}

int main() {
    std::cout << digitPowerSum(89, 1) << std::endl;
    std::cout << digitPowerSum(92, 1) << std::endl;
    std::cout << digitPowerSum(695, 2) << std::endl;
    std::cout << digitPowerSum(46288, 3) << std::endl;
    return 0;
}