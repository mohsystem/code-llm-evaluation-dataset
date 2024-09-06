
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int validateEmail(const char* email) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\\\.[a-zA-Z]{2,}$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\\n");
        exit(1);
    }

    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);

    return reti == 0;
}

int main() {
    char email[100];
    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\\n")] = 0; // Remove newline

    if (validateEmail(email)) {
        printf("Valid email address\\n");
    } else {
        printf("Invalid email address\\n");
    }

    return 0;
}
