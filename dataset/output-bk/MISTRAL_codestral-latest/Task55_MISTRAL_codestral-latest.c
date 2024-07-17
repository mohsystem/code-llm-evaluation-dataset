#include <stdio.h>
#include <regex.h>

int main() {
    char email[100];
    printf("Enter your email: ");
    scanf("%s", email);

    const char *emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\."
                            "[a-zA-Z0-9_+&*-]+)*@"
                            "(?:[a-zA-Z0-9-]+\\.)+[a-z"
                            "A-Z]{2,7}$";

    regex_t regex;
    int reti = regcomp(&regex, emailRegex, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        return 1;
    }

    reti = regexec(&regex, email, 0, NULL, 0);
    if (!reti) {
        printf("Valid email address
");
    } else if (reti == REG_NOMATCH) {
        printf("Invalid email address
");
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s
", msgbuf);
    }

    regfree(&regex);

    return 0;
}