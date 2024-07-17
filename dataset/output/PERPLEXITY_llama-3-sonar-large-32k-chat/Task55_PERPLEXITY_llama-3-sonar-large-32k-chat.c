#include <stdio.h>
#include <string.h>
#include <regex.h>

int validateEmail(char *email) {
    regex_t regex;
    int reti = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", 0);
    if (reti) {
        printf("Could not compile regex
");
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
    printf("Enter an email address:");
    scanf("%255s", email);
    if (validateEmail(email)) {
        printf("Valid email address
");
    } else {
        printf("Invalid email address
");
    }
    return 0;
}