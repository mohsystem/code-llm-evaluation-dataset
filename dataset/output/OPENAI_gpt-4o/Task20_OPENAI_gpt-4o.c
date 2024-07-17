#include <stdio.h>
#include <math.h>

int digPow(int n, int p) {
    int sum = 0, temp = n, digit, str_len = 0;

    while (temp > 0) {
        str_len++;
        temp /= 10;
    }

    temp = n;
    for (int i = str_len - 1; i >= 0; i--) {
        digit = temp / (int)pow(10, i);
        sum += (int)pow(digit, p++);
        temp %= (int)pow(10, i);
    }

    if (sum % n == 0) {
        return sum / n;
    } else {
        return -1;
    }
}

int main() {
    printf("%d
", digPow(89, 1));        // Output: 1
    printf("%d
", digPow(92, 1));        // Output: -1
    printf("%d
", digPow(695, 2));       // Output: 2
    printf("%d
", digPow(46288, 3));     // Output: 51
    return 0;
}