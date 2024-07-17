
#include <stdio.h>
#include <regex.h>
#include <string.h>

#define MAX_URL_LENGTH 2000

int main() {
    char url[MAX_URL_LENGTH];
    regex_t regex;
    int reti;

    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\
")] = 0;  // Remove newline

    reti = regcomp(&regex, "^(https?://)?([[:alnum:].-]+)\\\\.([[:alpha:]]{2,6})(:[0-9]+)?([/[:alnum:] .-]*)*/?$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\
");
        return 1;
    }

    reti = regexec(&regex, url, 0, NULL, 0);
    if (!reti) {
        printf("Valid URL\
");
    } else if (reti == REG_NOMATCH) {
        printf("Invalid URL\
");
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\
", msgbuf);
    }

    regfree(&regex);
    return 0;
}
