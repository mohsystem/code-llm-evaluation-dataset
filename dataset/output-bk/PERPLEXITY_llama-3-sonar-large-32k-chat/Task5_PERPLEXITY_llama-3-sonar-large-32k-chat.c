#include <stdio.h>

int persistence(long n) {
    int count = 0;
    while (n >= 10) {
        long mult = 1;
        while (n > 0) {
            mult *= n % 10;
            n /= 10;
        }
        n = mult;
        count++;
    }
    return count;
}

int main() {
    printf("%d
", persistence(39));  // 3
    printf("%d
", persistence(999)); // 4
    printf("%d
", persistence(4));   // 0
    return 0;
}