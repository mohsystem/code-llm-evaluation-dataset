#include <stdio.h>

int main() {
    int number;
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.
");
        return 1;
    }
    printf("The entered integer is: %d
", number);
    return 0;
}