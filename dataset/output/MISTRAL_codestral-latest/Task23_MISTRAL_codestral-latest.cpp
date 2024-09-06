#include <cmath>

long long findNb(long long m) {
    long long n = 1;
    while (std::pow(n, 3) < m) {
        m -= std::pow(n, 3);
        n++;
    }
    return (m == std::pow(n, 3)) ? n : -1;
}