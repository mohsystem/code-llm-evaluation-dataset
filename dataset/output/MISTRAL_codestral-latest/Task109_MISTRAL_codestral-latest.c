#include <stdio.h>
#include <regex.h>

int validateInput(const char* userInput) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    const char* pattern = "^[a-zA-Z0-9_]+$";

    reti = regcomp(&regex, pattern, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    reti = regexec(&regex, userInput, 0, NULL, 0);
    if (!reti) {
        return 1;
    } else if (reti == REG_NOMATCH) {
        return 0;
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 0;
    }

    regfree(&regex);
}

int main() {
    char userInput[100];
    printf("Enter your input: ");
    fgets(userInput, sizeof(userInput), stdin);
    if (validateInput(userInput)) {
        printf("Input is valid\n");
    } else {
        printf("Input is invalid\n");
    }
    return 0;
}