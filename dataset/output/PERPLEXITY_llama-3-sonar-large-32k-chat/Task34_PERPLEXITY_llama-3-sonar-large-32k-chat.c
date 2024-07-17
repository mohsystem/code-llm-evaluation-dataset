#include <math.h>
#include <stdio.h>

int isNarcissistic(int n) {
    int sum = 0, temp = n;
    int digits = 0;
    for (int i = n; i != 0; i /= 10) {
        digits++;
    }
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    printf("%d
", isNarcissistic(153)); // 1
    printf("%d
", isNarcissistic(1652)); // 0
    return 0;
}