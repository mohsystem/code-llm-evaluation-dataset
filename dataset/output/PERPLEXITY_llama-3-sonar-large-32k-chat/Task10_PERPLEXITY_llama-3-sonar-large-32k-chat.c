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
    printf("%d
", sumBetween(-1, 2));
    return 0;
}