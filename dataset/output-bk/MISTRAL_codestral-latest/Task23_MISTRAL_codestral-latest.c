#include <stdio.h>

long findNb(long m) {
    long n = 1;
    while (n * n * n < m) {
        m -= n * n * n;
        n++;
    }
    return (m == n * n * n) ? n : -1;
}