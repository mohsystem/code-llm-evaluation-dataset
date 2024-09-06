#include <regex.h>
#include <stdio.h>

int validate_ip(const char *ip) {
    regex_t regex;
    int reti;

    const char *pattern = "^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$";

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    reti = regexec(&regex, ip, 0, NULL, 0);
    if (!reti) {
        return 1;  // true
    } else if (reti == REG_NOMATCH) {
        return 0;  // false
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        return 0;
    }

    regfree(&regex);
}

int main() {
    printf("%d\n", validate_ip("192.168.1.1"));  // 1 (true)
    printf("%d\n", validate_ip("256.168.1.1"));  // 0 (false)
    return 0;
}