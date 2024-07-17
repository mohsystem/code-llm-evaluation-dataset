#include <math.h>

long long findNb(long long m) {
    long long n = 0;
    long long sum = 0;
    while (sum < m) {
        n++;
        sum += n * n * n;
    }
    return sum == m ? n : -1;
}