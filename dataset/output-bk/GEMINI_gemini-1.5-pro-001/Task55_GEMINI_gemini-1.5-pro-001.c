#include <stdio.h>
#include <regex.h>

int isValidEmail(const char *email) {
    regex_t regex;
    int reti;

    reti = regcomp(&regex, "^[A-Za-z0-9+_.-]+@(.+)$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        return 0;
    }

    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    return reti == 0;
}

int main() {
    const char *email = "user@example.com";
    if (isValidEmail(email)) {
        printf("Valid Email
");
    } else {
        printf("Invalid Email
");
    }
    return 0;
}