#include <stdio.h>

long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    printf("Enter a number:
");
    scanf("%d", &number);
    printf("Factorial: %ld
", factorial(number));
    return 0;
}