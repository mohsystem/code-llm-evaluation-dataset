#include <math.h>

long long findNb(long long m) {
    long long n = 1;
    while (pow(n, 3) < m) {
        m -= pow(n, 3);
        n++;
    }
    return (m == pow(n, 3)) ? n : -1;
}