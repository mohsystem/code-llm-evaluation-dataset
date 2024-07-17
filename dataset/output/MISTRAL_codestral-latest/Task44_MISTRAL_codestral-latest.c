#include <stdio.h>

int main() {
    double num;

    printf("Enter a number: ");

    if (scanf("%lf", &num) == 1) {
        printf("The square of the number is: %.2lf
", num * num);
    } else {
        printf("Invalid input. Please enter a number.
");
    }

    return 0;
}