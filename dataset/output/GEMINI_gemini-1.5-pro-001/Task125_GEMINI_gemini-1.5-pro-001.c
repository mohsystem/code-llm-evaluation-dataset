#include <stdio.h>
#include <string.h>

int main() {
    char userInput[100];

    printf("Enter your choice: ");
    scanf("%s", userInput);

    if (strcmp(userInput, "option1") == 0) {
        printf("Accessing resource 1...
");
    } else if (strcmp(userInput, "option2") == 0) {
        printf("Accessing resource 2...
");
    } else {
        printf("Invalid choice.
");
    }

    return 0;
}