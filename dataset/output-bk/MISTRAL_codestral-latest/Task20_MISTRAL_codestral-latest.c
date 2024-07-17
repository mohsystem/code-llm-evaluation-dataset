// C
#include <stdio.h>
#include <math.h>

int digPow(int n, int p) {
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        sum += pow(temp % 10, p++);
        temp /= 10;
    }
    return sum % n == 0 ? sum / n : -1;
}

int main() {
    printf("%d
", digPow(89, 1));
    printf("%d
", digPow(92, 1));
    printf("%d
", digPow(695, 2));
    printf("%d
", digPow(46288, 3));
    return 0;
}