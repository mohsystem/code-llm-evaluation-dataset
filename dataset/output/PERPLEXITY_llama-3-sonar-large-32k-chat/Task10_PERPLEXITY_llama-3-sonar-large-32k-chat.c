#include <stdio.h>

int sumBetween(int a, int b) {
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    int sum = 0;
    for (int i = min; i <= max; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    printf("%d\n", sumBetween(1, 0));
    printf("%d\n", sumBetween(1, 2));
    printf("%d\n", sumBetween(0, 1));
    printf("%d\n", sumBetween(1, 1));
    printf("%d\n", sumBetween(-1, 0));
    printf("%d\n", sumBetween(-1, 2));
    return 0;
}