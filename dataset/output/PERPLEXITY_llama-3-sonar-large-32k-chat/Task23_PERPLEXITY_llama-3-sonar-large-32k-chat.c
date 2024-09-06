#include <math.h>

long long findNb(long long m) {
    long long n = 1;
    long long volume = 0;
    while (volume < m) {
        volume += (long long) pow(n, 3);
        if (volume == m) {
            return n;
        }
        n++;
    }
    return -1;
}