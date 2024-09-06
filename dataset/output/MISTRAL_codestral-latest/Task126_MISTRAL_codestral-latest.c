// C
#include <stdio.h>
#include <string.h>

int main() {
    char userInput[20];
    printf("Enter your input: ");
    scanf("%s", userInput);

    if (strcmp(userInput, "home") == 0) {
        printf("Redirecting to home page...\n");
    } else if (strcmp(userInput, "about") == 0) {
        printf("Redirecting to about page...\n");
    } else if (strcmp(userInput, "contact") == 0) {
        printf("Redirecting to contact page...\n");
    } else {
        printf("Invalid input. Redirecting to default page...\n");
    }

    return 0;
}