
#include <stdio.h>

int persistence(long long n) {
    if (n < 10) return 0;
    int count = 0;
    while (n >= 10) {
        long long product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        n = product;
        count++;
    }
    return count;
}

int main() {
    printf("%d\
", persistence(39));  // Output: 3
    printf("%d\
", persistence(999)); // Output: 4
    printf("%d\
", persistence(4));   // Output: 0
    return 0;
}
