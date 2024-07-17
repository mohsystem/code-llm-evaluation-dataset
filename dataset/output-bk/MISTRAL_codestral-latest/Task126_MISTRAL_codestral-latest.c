#include <stdio.h>
#include <string.h>

void redirectUser(char* input) {
    if (strcmp(input, "home") == 0) {
        printf("Redirecting to home page...
");
    } else if (strcmp(input, "about") == 0) {
        printf("Redirecting to about page...
");
    } else if (strcmp(input, "contact") == 0) {
        printf("Redirecting to contact page...
");
    } else {
        printf("Invalid input. Staying on current page.
");
    }
}

int main() {
    char input[20];
    printf("Enter a page: ");
    scanf("%s", input);

    redirectUser(input);

    return 0;
}