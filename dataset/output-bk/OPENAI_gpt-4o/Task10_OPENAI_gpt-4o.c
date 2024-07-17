#include <stdio.h>

int sum_integers(int a, int b) {
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    int sum = 0;

    for (int i = min; i <= max; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    printf("%d
", sum_integers(1, 0));  // 1
    printf("%d
", sum_integers(1, 2));  // 3
    printf("%d
", sum_integers(0, 1));  // 1
    printf("%d
", sum_integers(1, 1));  // 1
    printf("%d
", sum_integers(-1, 0));  // -1
    printf("%d
", sum_integers(-1, 2));  // 2

    return 0;
}