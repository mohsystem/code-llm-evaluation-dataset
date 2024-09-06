#include <stdio.h>

int main() {
    int number;
    long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++) {
        factorial *= i;
    }

    printf("The factorial of %d is %lld\n", number, factorial);

    return 0;
}