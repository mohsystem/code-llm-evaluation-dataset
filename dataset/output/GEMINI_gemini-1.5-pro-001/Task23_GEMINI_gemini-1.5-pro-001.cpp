#include <cmath>

long long findNb(long long m) {
    long long n = 0;
    long long sum = 0;
    while (sum < m) {
        n++;
        sum += pow(n, 3);
    }
    return sum == m ? n : -1;
}