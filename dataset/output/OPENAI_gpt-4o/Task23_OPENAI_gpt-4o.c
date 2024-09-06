#include <stdio.h>
#include <math.h>

long findNb(long m) {
    long n = 0, totalVolume = 0;
    while (totalVolume < m) {
        n++;
        totalVolume += pow(n, 3);
    }
    return totalVolume == m ? n : -1;
}

int main() {
    printf("%ld\n", findNb(1071225));  // 45
    printf("%ld\n", findNb(91716553919377));  // -1
    return 0;
}