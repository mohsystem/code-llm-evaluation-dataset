
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

bool isValidURL(const char* url) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, "^(https?|ftp)://[^[:space:]/$.?#].[^[:space:]]*$", REG_EXTENDED | REG_ICASE);
    if (reti) {
        fprintf(stderr, "Could not compile regex\\n");
        return false;
    }

    reti = regexec(&regex, url, 0, NULL, 0);
    if (!reti) {
        regfree(&regex);
        return true;
    }
    else if (reti == REG_NOMATCH) {
        regfree(&regex);
        return false;
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\\n", msgbuf);
        regfree(&regex);
        return false;
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    while (1) {
        printf("Enter a URL (or 'quit' to exit): ");
        fgets(url, sizeof(url), stdin);
        url[strcspn(url, "\\n")] = 0;  // Remove newline

        if (strcmp(url, "quit") == 0) {
            break;
        }

        if (isValidURL(url)) {
            printf("Valid URL\\n");
        } else {
            printf("Invalid URL\\n");
        }
    }
    return 0;
}
