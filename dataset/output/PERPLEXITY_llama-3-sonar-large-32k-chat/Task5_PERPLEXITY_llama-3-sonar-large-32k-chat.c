#include <stdio.h>

int multiplyDigits(int n) {
    int product = 1;
    while (n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

int persistence(int n) {
    int count = 0;
    while (n >= 10) {
        n = multiplyDigits(n);
        count++;
    }
    return count;
}