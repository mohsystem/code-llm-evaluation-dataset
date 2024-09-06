#include <stdio.h>
#include <stdlib.h>

int getIntegerInput(const char* prompt) {
    int value;
    char input[256];

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "%d", &value) == 1) {
            return value;
        } else {
            printf("Invalid input. Please enter an integer.\n");
        }
    }
}

int main() {
    int num1 = getIntegerInput("Enter the first number: ");
    int num2 = getIntegerInput("Enter the second number: ");

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;

    printf("The sum is: %d\n", sum);
    printf("The difference is: %d\n", difference);
    printf("The product is: %d\n", product);

    return 0;
}