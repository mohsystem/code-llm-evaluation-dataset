#include <stdio.h>

int performOperation(int input);

int main() {
    int userInput;
    printf("Enter an integer: ");
    if(scanf("%d", &userInput) == 1) {
        int result = performOperation(userInput);
        printf("The result from C operation is: %d
", result);
    } else {
        printf("Invalid input.
");
    }
    return 0;
}

int performOperation(int input) {
    return input * 2;
}