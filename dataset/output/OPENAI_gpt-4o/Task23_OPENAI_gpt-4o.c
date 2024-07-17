#include <stdio.h>

long findNb(long long m) {
    long n = 0;
    long long volume = 0;
    
    while (volume < m) {
        n++;
        volume += (long long)n * n * n;
    }
    
    if (volume == m) {
        return n;
    } else {
        return -1;
    }
}

int main() {
    printf("%ld
", findNb(1071225)); // 45
    printf("%ld
", findNb(91716553919377LL)); // -1
    return 0;
}