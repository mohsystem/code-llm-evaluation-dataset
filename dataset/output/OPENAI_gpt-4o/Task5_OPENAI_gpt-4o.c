#include <stdio.h>

int multiplyDigits(int num) {
    int product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

int persistence(int num) {
    int count = 0;
    while (num >= 10) {
        num = multiplyDigits(num);
        count++;
    }
    return count;
}

int main() {
    printf("%d
", persistence(39)); // should return 3
    printf("%d
", persistence(999)); // should return 4
    printf("%d
", persistence(4)); // should return 0
    return 0;
}