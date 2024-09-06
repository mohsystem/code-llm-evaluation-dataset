
#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    long long result = factorial(num);
    printf("The factorial of %d is %lld\\n", num, result);
    return 0;
}
