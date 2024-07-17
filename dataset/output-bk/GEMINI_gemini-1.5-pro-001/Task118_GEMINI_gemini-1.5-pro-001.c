#include <stdio.h>
#include <string.h>
#include <regex.h>

int main() {
    char ipAddress[] = "192.168.1.1";
    if (isValidIP(ipAddress)) {
        printf("%s is a valid IP address.
", ipAddress);
    } else {
        printf("%s is not a valid IP address.
", ipAddress);
    }
    return 0;
}

int isValidIP(char *ipAddress) {
    regex_t regex;
    int result;
    char *pattern = "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$";

    result = regexec(&regex, ipAddress, 0, NULL, 0);
    regfree(&regex);

    if (result == 0) {
        return 1; // Valid IP address
    } else {
        return 0; // Invalid IP address
    }
}