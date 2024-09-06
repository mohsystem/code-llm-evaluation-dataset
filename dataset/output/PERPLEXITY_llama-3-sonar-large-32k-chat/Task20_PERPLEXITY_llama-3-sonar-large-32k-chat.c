#include <math.h>
#include <string.h>

long long digPow(int n, int p) {
    char strN[20];
    sprintf(strN, "%d", n);
    long long sumOfPowers = 0;
    for (int i = 0; i < strlen(strN); i++) {
        sumOfPowers += pow(strN[i] - '0', p + i);
    }
    long long k = sumOfPowers / n;
    return k * n == sumOfPowers ? k : -1;
}