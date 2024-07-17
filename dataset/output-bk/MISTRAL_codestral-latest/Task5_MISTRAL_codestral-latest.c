#include <stdio.h>

int persistence(int num) {
    int count = 0;
    while (num >= 10) {
        int product = 1;
        while (num > 0) {
            product *= num % 10;
            num /= 10;
        }
        num = product;
        count++;
    }
    return count;
}

int main() {
    printf("%d
", persistence(39)); // Output: 3
    printf("%d
", persistence(999)); // Output: 4
    printf("%d
", persistence(4)); // Output: 0
    return 0;
}