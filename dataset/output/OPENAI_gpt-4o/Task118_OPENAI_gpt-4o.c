#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

bool validateIP(const char *ip) {
    regex_t regex;
    const char *pattern = "^([0-9]{1,3}\\.){3}[0-9]{1,3}$";
    if (regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        return false;
    }
    if (regexec(&regex, ip, 0, NULL, 0) != 0) {
        regfree(&regex);
        return false;
    }
    regfree(&regex);
    
    char ipCopy[16];
    strcpy(ipCopy, ip);
    char *token = strtok(ipCopy, ".");
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0 || num > 255) {
            return false;
        }
        token = strtok(NULL, ".");
    }
    return true;
}

int main() {
    const char *ips[] = {"192.168.1.1", "256.256.256.256", "123.045.067.089"};
    printf("Validated IPs: ");
    for (int i = 0; i < 3; i++) {
        if (validateIP(ips[i])) {
            printf("%s ", ips[i]);
        }
    }
    return 0;
}