#include <iostream>

long long findNb(long long m) {
    long long n = 0;
    long long volume = 0;
    
    while (volume < m) {
        n++;
        volume += n * n * n;
    }
    
    if (volume == m) {
        return n;
    } else {
        return -1;
    }
}

int main() {
    std::cout << findNb(1071225) << std::endl; // 45
    std::cout << findNb(91716553919377LL) << std::endl; // -1
    return 0;
}