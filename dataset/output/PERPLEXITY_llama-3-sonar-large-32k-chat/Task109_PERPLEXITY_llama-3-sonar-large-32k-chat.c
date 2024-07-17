#include <stdio.h>
#include <regex.h>

int main() {
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, "^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        exit(1);
    }

    /* Get user input */
    char email[100];
    printf("Enter your email:");
    scanf("%99s", email);

    /* Execute regular expression */
    reti = regexec(&regex, email, 0, NULL, 0);
    if (!reti) {
        printf("Email is valid
");
    } else {
        printf("Email is not valid
");
    }

    /* Free compiled regular expression */
    regfree(&regex);

    return 0;
}