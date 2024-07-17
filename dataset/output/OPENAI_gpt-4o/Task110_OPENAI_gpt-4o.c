#include <stdio.h>
#include <string.h>
#include <regex.h>

int isValidURL(const char *url) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, "^(http|https|ftp)://[^\\s/$.?#].[^\\s]*$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    reti = regexec(&regex, url, 0, NULL, 0);
    if (!reti) {
        regfree(&regex);
        return 1;
    } else if (reti == REG_NOMATCH) {
        regfree(&regex);
        return 0;
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        regfree(&regex);
        return 0;
    }
}

int main() {
    const char *urls[] = {
        "http://example.com",
        "https://example.com",
        "ftp://example.com",
        "invalidurl.com"
    };

    for (int i = 0; i < 4; i++) {
        printf("%s is %s\n", urls[i], isValidURL(urls[i]) ? "valid" : "invalid");
    }

    return 0;
}
