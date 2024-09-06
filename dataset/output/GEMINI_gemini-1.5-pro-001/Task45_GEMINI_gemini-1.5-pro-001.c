#include <stdio.h>
#include <stdlib.h>

int get_integer_input(char *prompt) {
    int input;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1) {
            return input;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
}

double perform_operation(int choice, int num1, int num2) {
    switch (choice) {
        case 1:
            return num1 + num2;
        case 2:
            return num1 - num2;
        case 3:
            return num1 * num2;
        case 4:
            if (num2 == 0) {
                printf("Error: Cannot divide by zero.\n");
                exit(1); 
            }
            return (double)num1 / num2;
        default:
            printf("Error: Invalid choice.\n");
            exit(1);
    }
}

int main() {
    while (1) {
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        int choice = get_integer_input("Enter your choice (1-5): ");

        if (choice == 5) {
            break;
        }

        if (choice >= 1 && choice <= 4) {
            int num1 = get_integer_input("Enter the first number: ");
            int num2 = get_integer_input("Enter the second number: ");

            double result = perform_operation(choice, num1, num2);
            printf("Result: %f\n", result);
        } else {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}