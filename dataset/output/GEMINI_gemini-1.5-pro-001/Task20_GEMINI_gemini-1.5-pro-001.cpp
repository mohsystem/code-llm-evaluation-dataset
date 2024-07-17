#include <iostream>
#include <cmath>

using namespace std;

long long digPow(long long n, long long p) {
    long long num = n, sum = 0, digit, i;
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    num = n;
    for (i = len - 1; i >= 0; i--, p++) {
        digit = (long long)(num / pow(10, i));
        num = (long long)(fmod(num, pow(10, i)));
        sum += (long long)pow(digit, p);
    }
    return (sum % n == 0) ? sum / n : -1;
}

int main() {
    cout << digPow(89, 1) << endl;
    cout << digPow(92, 1) << endl;
    cout << digPow(695, 2) << endl;
    cout << digPow(46288, 3) << endl;
    return 0;
}