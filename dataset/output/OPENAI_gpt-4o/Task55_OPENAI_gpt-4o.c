#include <stdio.h>
#include <regex.h>

int validateEmail(const char *email) {
    const char *pattern = "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$";
    regex_t regex;
    int result;

    result = regcomp(&regex, pattern, REG_EXTENDED);
    if (result) {
        return 0;
    }

    result = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    if (!result) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[100];
    printf("Enter an email address: ");
    scanf("%s", email);

    if (validateEmail(email)) {
        printf("Valid email address\n");
    } else {
        printf("Invalid email address\n");
    }

    return 0;
}