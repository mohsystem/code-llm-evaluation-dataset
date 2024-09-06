#include <math.h>

long long find_nb(long long m) {
    long long n = 1;
    long long total = 0;
    while (total < m) {
        total += pow(n, 3);
        if (total == m) {
            return n;
        }
        n++;
    }
    return -1;
}