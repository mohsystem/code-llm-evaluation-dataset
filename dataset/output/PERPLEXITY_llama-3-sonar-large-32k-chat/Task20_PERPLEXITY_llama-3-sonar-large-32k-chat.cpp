#include <cmath>
#include <string>

long long digPow(int n, int p) {
    std::string strN = std::to_string(n);
    long long sumOfPowers = 0;
    for (int i = 0; i < strN.length(); i++) {
        sumOfPowers += pow(strN[i] - '0', p + i);
    }
    long long k = sumOfPowers / n;
    return k * n == sumOfPowers ? k : -1;
}