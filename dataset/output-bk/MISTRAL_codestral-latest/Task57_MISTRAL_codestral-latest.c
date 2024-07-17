#include <stdio.h>

int main() {
    int num;
    long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    for(int i = 1; i <= num; ++i) {
        factorial *= i;
    }

    printf("Factorial of %d = %ld", num, factorial);

    return 0;
}