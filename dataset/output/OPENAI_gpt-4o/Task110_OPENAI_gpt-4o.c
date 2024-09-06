#include <stdio.h>
#include <stdbool.h>
#include <regex.h>

bool validateURL(const char *url) {
    regex_t regex;
    const char *pattern = "^(http|https|ftp)://([^\\s/$.?#].[^\\s]*)$";
    if (regcomp(&regex, pattern, REG_EXTENDED | REG_ICASE) != 0)
        return false;

    int reti = regexec(&regex, url, 0, NULL, 0);
    regfree(&regex);
    return reti == 0;
}

int main() {
    char userURL[256];
    printf("Enter URL: ");
    scanf("%s", userURL);

    if (validateURL(userURL)) {
        printf("Valid URL\n");
    } else {
        printf("Invalid URL\n");
    }

    return 0;
}