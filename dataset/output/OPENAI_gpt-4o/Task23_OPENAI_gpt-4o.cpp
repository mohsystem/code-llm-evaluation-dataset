#include <iostream>
#include <cmath>

long findNb(long m) {
    long n = 0, totalVolume = 0;
    while (totalVolume < m) {
        n++;
        totalVolume += pow(n, 3);
    }
    return totalVolume == m ? n : -1;
}

int main() {
    std::cout << findNb(1071225) << std::endl;  // 45
    std::cout << findNb(91716553919377) << std::endl;  // -1
    return 0;
}