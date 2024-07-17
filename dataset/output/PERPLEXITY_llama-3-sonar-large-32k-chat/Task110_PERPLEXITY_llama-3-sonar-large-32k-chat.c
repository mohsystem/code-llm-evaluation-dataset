#include <stdio.h>
#include <string.h>
#include <regex.h>

int main() {
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, "^((https?|ftp|file)://)?(-\\w+\\.){1,}(com|org|net|gov|mil|biz|info|mobi|name|aero|jobs|edu|co\\.uk|ac\\.uk|gov\\.uk|mil\\.uk|nhs\\.uk|police\\.uk|mod\\.uk|travel|local|me\\.uk|ltd\\.uk|plc\\.uk|net\\.uk|sch\\.uk)(:\\d+)?(/([\\w\\-\\.\\?\\,\\\\\\+&%*#=]*)?)?$", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        exit(1);
    }

    /* Get URL from user */
    char url[1024];
    printf("Enter a URL: ");
    fgets(url, 1024, stdin);
    url[strcspn(url, "
")] = 0; // remove newline character

    /* Execute regular expression */
    reti = regexec(&regex, url, 0, NULL, 0);
    if (!reti) {
        printf("URL is valid
");
    } else {
        printf("URL is not valid
");
    }

    /* Free compiled regular expression */
    regfree(&regex);

    return 0;
}