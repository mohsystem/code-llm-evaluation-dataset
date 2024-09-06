#include <stdio.h>
#include <regex.h>

int main() {
    char email[100];
    regex_t regex;
    int result;

    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0; // remove trailing newline

    // Compile the regular expression
    result = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", REG_EXTENDED);
    if (result) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    // Match the email address against the regex
    result = regexec(&regex, email, 0, NULL, 0);
    if (!result) {
        printf("Valid email address\n");
    } else if (result == REG_NOMATCH) {
        printf("Invalid email address\n");
    } else {
        char msgbuf[100];
        regerror(result, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 1;
    }

    // Free the compiled regex
    regfree(&regex);
    return 0;
}