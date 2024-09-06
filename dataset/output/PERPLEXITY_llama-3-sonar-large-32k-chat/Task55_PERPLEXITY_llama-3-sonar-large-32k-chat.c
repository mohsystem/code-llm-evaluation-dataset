#include <stdio.h>
#include <regex.h>

int validateEmail(const char *email) {
    regex_t regex;
    int reti = regcomp(&regex, "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$", 0);
    if (reti) {
        printf("Could not compile regex\n");
        return 0;
    }
    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    if (!reti) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[256];
    printf("Enter an email address: ");
    fgets(email, 256, stdin);
    email[strcspn(email, "\n")] = 0; // remove newline character
    if (validateEmail(email)) {
        printf("Valid email address\n");
    } else {
        printf("Invalid email address\n");
    }
    return 0;
}