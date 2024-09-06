
#include <stdio.h>
#include <regex.h>
#include <string.h>

#define MAX_INPUT 100

int validate_regex(const char* pattern, const char* input) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\\n");
        return 0;
    }

    reti = regexec(&regex, input, 0, NULL, 0);
    if (!reti) {
        regfree(&regex);
        return 1;
    } else if (reti == REG_NOMATCH) {
        regfree(&regex);
        return 0;
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\\n", msgbuf);
        regfree(&regex);
        return 0;
    }
}

int main() {
    char input[MAX_INPUT];

    // Email validation
    printf("Enter your email: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\\n")] = 0;
    if (validate_regex("^[[:alnum:]\\\\.-]+@[[:alnum:]\\\\.-]+\\\\.[[:alpha:]]+$", input)) {
        printf("Valid email\\n");
    } else {
        printf("Invalid email\\n");
    }

    // Phone number validation (US format)
    printf("Enter your phone number: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\\n")] = 0;
    if (validate_regex("^\\\\(?([0-9]{3})\\\\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$", input)) {
        printf("Valid phone number\\n");
    } else {
        printf("Invalid phone number\\n");
    }

    // Password validation (at least 8 characters, 1 uppercase, 1 lowercase, 1 digit)
    printf("Enter your password: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\\n")] = 0;
    if (validate_regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])[a-zA-Z0-9]{8,}$", input)) {
        printf("Valid password\\n");
    } else {
        printf("Invalid password\\n");
    }

    return 0;
}
