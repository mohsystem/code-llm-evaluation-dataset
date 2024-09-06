#include <stdio.h>
#include <math.h>

int dig_pow(int n, int p) {
    int temp = n, sum = 0, len = 0;

    // Get number of digits
    while (temp > 0) {
        temp /= 10;
        len++;
    }

    temp = n;
    for (int i = len - 1; i >= 0; i--) {
        int digit = (temp / (int) pow(10, i)) % 10;
        sum += pow(digit, p++);
    }

    return sum % n == 0 ? sum / n : -1;
}

int main() {
    printf("%d\n", dig_pow(89, 1));     // Output: 1
    printf("%d\n", dig_pow(92, 1));     // Output: -1
    printf("%d\n", dig_pow(695, 2));    // Output: 2
    printf("%d\n", dig_pow(46288, 3));  // Output: 51
    return 0;
}