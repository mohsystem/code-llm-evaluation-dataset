#include <iostream>
#include <cmath>

long long findNb(long long m) {
    long long n = 1;
    long long sum = 0;
    while (sum < m) {
        sum += pow(n, 3);
        if (sum == m) {
            return n;
        }
        n++;
    }
    return -1;
}

int main() {
    std::cout << findNb(1071225) << std::endl; // 45
    std::cout << findNb(91716553919377LL) << std::endl; // -1
    return 0;
}