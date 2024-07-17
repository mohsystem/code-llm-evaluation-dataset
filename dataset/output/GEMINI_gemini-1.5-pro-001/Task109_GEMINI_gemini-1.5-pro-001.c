#include <stdio.h>
#include <regex.h>

int main() {
    char email[100];
    regex_t regex;
    int result;

    printf("Enter email address: ");
    fgets(email, sizeof(email), stdin);

    // Remove newline character from fgets()
    email[strcspn(email, "
")] = 0;

    // Compile the regular expression
    result = regcomp(&regex, "^[A-Za-z0-9+_.-]+@(.+)$", REG_EXTENDED);
    if (result) {
        fprintf(stderr, "Could not compile regex
");
        return 1;
    }

    // Match the email against the regex
    result = regexec(&regex, email, 0, NULL, 0);
    if (!result) {
        printf("Valid email address
");
    } else {
        printf("Invalid email address
");
    }

    // Free the compiled regex
    regfree(&regex);

    return 0;
}