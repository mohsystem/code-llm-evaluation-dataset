#include <stdio.h>
#include <math.h>

long findNb(long m) {
    long n = 1;
    long sum = 0;
    while (sum < m) {
        sum += (long) pow(n, 3);
        if (sum == m) {
            return n;
        }
        n++;
    }
    return -1;
}

int main() {
    printf("%ld
", findNb(1071225)); // 45
    printf("%ld
", findNb(91716553919377L)); // -1
    return 0;
}