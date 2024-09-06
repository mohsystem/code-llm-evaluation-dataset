#include <stdio.h>
#include <regex.h>
#include <string.h>

int main() {
    char user_input[100];
    printf("Enter something: ");
    fgets(user_input, 100, stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // remove trailing newline

    regex_t regex;
    int reti = regcomp(&regex, "^[a-zA-Z0-9_]+$", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }

    reti = regexec(&regex, user_input, 0, NULL, 0);
    if (!reti) {
        printf("Valid input\n");
    } else if (reti == REG_NOMATCH) {
        printf("Invalid input\n");
    } else {
        fprintf(stderr, "Regex match failed\n");
        return 1;
    }

    regfree(&regex);
    return 0;
}