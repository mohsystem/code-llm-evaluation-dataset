#include <stdio.h>

int main() {
    double number;
    printf("Enter a number: ");
    if (scanf("%lf", &number) == 1) {
        double result = number * 2;
        printf("The result is: %.2lf\n", result);
    } else {
        printf("Invalid input. Please enter a number.\n");
    }
    return 0;
}