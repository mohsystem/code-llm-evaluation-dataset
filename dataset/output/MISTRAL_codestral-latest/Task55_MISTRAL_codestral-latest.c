#include <stdio.h>
#include <regex.h>

int validateEmail(const char* email) {
    regex_t regex;
    int reti;
    const char* pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    if (!reti) {
        return 1;
    } else if (reti == REG_NOMATCH) {
        return 0;
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 0;
    }
}

int main() {
    char email[100];
    printf("Enter your email: ");
    scanf("%s", email);
    if (validateEmail(email)) {
        printf("Email is valid\n");
    } else {
        printf("Email is invalid\n");
    }
    return 0;
}