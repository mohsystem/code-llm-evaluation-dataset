// C++
#include <iostream>
#include <cmath>

int digPow(int n, int p) {
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        sum += pow(temp % 10, p++);
        temp /= 10;
    }
    return sum % n == 0 ? sum / n : -1;
}

int main() {
    std::cout << digPow(89, 1) << std::endl;
    std::cout << digPow(92, 1) << std::endl;
    std::cout << digPow(695, 2) << std::endl;
    std::cout << digPow(46288, 3) << std::endl;
    return 0;
}