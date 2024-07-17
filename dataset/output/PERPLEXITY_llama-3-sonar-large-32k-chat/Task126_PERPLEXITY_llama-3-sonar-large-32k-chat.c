#include <stdio.h>
#include <string.h>

void redirectUser() {
    char userInput[20];
    printf("Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'exit' to exit: ");
    scanf("%s", userInput);
    if (strcmp(userInput, "google") == 0) {
        printf("Redirecting to Google...
");
    } else if (strcmp(userInput, "facebook") == 0) {
        printf("Redirecting to Facebook...
");
    } else if (strcmp(userInput, "exit") == 0) {
        printf("Exiting...
");
    } else {
        printf("Invalid input. Please try again.
");
        redirectUser();
    }
}

int main() {
    redirectUser();
    return 0;
}