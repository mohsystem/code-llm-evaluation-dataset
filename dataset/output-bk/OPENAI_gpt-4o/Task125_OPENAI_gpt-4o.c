#include <stdio.h>
#include <string.h>

int main() {
    char userInput[50];
    char *resource1 = "resource1";
    char *resource2 = "resource2";

    printf("Enter your resource: ");
    scanf("%s", userInput);

    if (strcmp(userInput, resource1) == 0) {
        printf("Access to Resource 1
");
    } else if (strcmp(userInput, resource2) == 0) {
        printf("Access to Resource 2
");
    } else {
        printf("Resource not found
");
    }

    return 0;
}