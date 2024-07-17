#include <stdio.h>

int getSum(int a, int b) {
    if (a == b) {
        return a;
    } else if (a < b) {
        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += i;
        }
        return sum;
    } else {
        int sum = 0;
        for (int i = b; i <= a; i++) {
            sum += i;
        }
        return sum;
    }
}

int main() {
    printf("%d
", getSum(1, 0)); // Output: 1
    printf("%d
", getSum(1, 2)); // Output: 3
    printf("%d
", getSum(0, 1)); // Output: 1
    printf("%d
", getSum(1, 1)); // Output: 1
    printf("%d
", getSum(-1, 0)); // Output: -1
    printf("%d
", getSum(-1, 2)); // Output: 2
    return 0;
}