#include <stdio.h>

int multiplyDigits(int num) {
    int result = 1;
    while (num > 0) {
        result *= num % 10;
        num /= 10;
    }
    return result;
}

int persistence(int num) {
    int count = 0;
    while (num >= 10) {
        num = multiplyDigits(num);
        count += 1;
    }
    return count;
}

int main() {
    printf("%d\n", persistence(39));  // 3
    printf("%d\n", persistence(999)); // 4
    printf("%d\n", persistence(4));   // 0

    return 0;
}