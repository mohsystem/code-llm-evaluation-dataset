#include <stdio.h>
#include <regex.h>

int main() {
    char url[1024];
    regex_t regex;
    int result;

    printf("Enter a URL to validate: ");
    fgets(url, sizeof(url), stdin);

    // Remove trailing newline character from fgets()
    if (url[strlen(url) - 1] == '
') {
        url[strlen(url) - 1] = '\0';
    }

    // Regular expression for URL validation
    result = regcomp(&regex, "^(http|https)://([a-z0-9]+(-[a-z0-9]+)*\.)+[a-z]{2,6}(:[0-9]+)?(/.*)?$", REG_EXTENDED | REG_NOSUB);
    if (result) {
        fprintf(stderr, "Could not compile regex
");
        return 1;
    }

    result = regexec(&regex, url, 0, NULL, 0);
    if (!result) {
        printf("%s is a valid URL.
", url);
    } else if (result == REG_NOMATCH) {
        printf("%s is not a valid URL.
", url);
    } else {
        char msgbuf[100];
        regerror(result, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s
", msgbuf);
        return 1;
    }

    regfree(&regex);
    return 0;
}