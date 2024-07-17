#include <stdio.h>
#include <math.h>

int digitPowerSum(int n, int p) {
    int sum = 0;
    int temp = n;
    int i = 0;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, p + i);
        temp /= 10;
        i++;
    }
    if (sum % n == 0) {
        return sum / n;
    } else {
        return -1;
    }
}

int main() {
    printf("%d
", digitPowerSum(89, 1));
    printf("%d
", digitPowerSum(92, 1));
    printf("%d
", digitPowerSum(695, 2));
    printf("%d
", digitPowerSum(46288, 3));
    return 0;
}