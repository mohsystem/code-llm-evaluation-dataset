#include <stdio.h>
#include <regex.h>

int isValidIP(const char *ip) {
    regex_t regex;
    int ret;
    const char *pattern = "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$";

    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        fprintf(stderr, "Could not compile regex
");
        return 0;
    }

    ret = regexec(&regex, ip, 0, NULL, 0);
    regfree(&regex);

    return !ret;
}

int main() {
    const char *ip = "192.168.1.1";
    if (isValidIP(ip)) {
        printf("%s is a valid IP address.
", ip);
    } else {
        printf("%s is not a valid IP address.
", ip);
    }

    return 0;
}