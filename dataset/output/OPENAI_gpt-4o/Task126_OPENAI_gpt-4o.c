#include <stdio.h>
#include <string.h>

void redirect(const char *input) {
    if (strcmp(input, "home") == 0) {
        printf("Redirect to Home Page\n");
    } else if (strcmp(input, "about") == 0) {
        printf("Redirect to About Page\n");
    } else if (strcmp(input, "contact") == 0) {
        printf("Redirect to Contact Page\n");
    } else {
        printf("Page not found\n");
    }
}

int main() {
    char input[20];
    printf("Enter page to redirect to (home/about/contact): ");
    scanf("%19s", input);
    redirect(input);
    return 0;
}