#include <stdio.h>
#include <regex.h>

int isValidURL(const char *url) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    const char *urlPattern = "^(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]";

    reti = regcomp(&regex, urlPattern, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        return 0;
    }

    reti = regexec(&regex, url, 0, NULL, 0);
    if (!reti) {
        return 1;
    } else if (reti == REG_NOMATCH) {
        return 0;
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s
", msgbuf);
        return 0;
    }

    regfree(&regex);
}

int main() {
    const char *url = "http://www.example.com";
    if (isValidURL(url)) {
        printf("URL is valid
");
    } else {
        printf("URL is not valid
");
    }
    return 0;
}