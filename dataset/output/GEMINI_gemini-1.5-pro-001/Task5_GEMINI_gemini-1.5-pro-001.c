#include <stdio.h>

int persistence(long long num) {
    if (num < 10) {
        return 0;
    }
    int count = 0;
    while (num >= 10) {
        long long prod = 1;
        while (num > 0) {
            prod *= (num % 10);
            num /= 10;
        }
        num = prod;
        count++;
    }
    return count;
}

int main() {
    printf("%d\n", persistence(39));
    printf("%d\n", persistence(999));
    printf("%d\n", persistence(4));
    return 0;
}