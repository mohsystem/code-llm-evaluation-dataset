#include <stdio.h>

int main() {
    int num, num2;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid number.
");
        return 1;
    }
    printf("You entered: %d
", num);
    printf("Enter another number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input. Please enter a valid number.
");
        return 1;
    }
    printf("You entered: %d
", num2);
    if (num2 == 0) {
        printf("Cannot divide by zero.
");
        return 1;
    }
    int result = num / num2;
    printf("Result: %d
", result);
    return 0;
}