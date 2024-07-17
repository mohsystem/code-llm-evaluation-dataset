
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long digPow(int n, int p) {
    char digits[20];
    sprintf(digits, "%d", n);
    int len = strlen(digits);
    long long sum = 0;
    for (int i = 0; i < len; i++) {
        int digit = digits[i] - \'0\';
        sum += pow(digit, p + i);
    }
    if (sum % n == 0) {
        return sum / n;
    }
    return -1;
}

int main() {
    printf("%lld\
", digPow(89, 1));
    printf("%lld\
", digPow(92, 1));
    printf("%lld\
", digPow(695, 2));
    printf("%lld\
", digPow(46288, 3));
    return 0;
}
