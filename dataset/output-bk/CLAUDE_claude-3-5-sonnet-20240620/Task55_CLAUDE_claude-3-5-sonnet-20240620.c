
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_EMAIL_LENGTH 100

int is_valid_email(const char* email) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, "^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\
");
        exit(1);
    }

    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    return reti == 0;
}

int main() {
    char email[MAX_EMAIL_LENGTH];

    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\
")] = 0;  // Remove newline

    if (is_valid_email(email)) {
        printf("Valid email address\
");
    } else {
        printf("Invalid email address\
");
    }

    return 0;
}
