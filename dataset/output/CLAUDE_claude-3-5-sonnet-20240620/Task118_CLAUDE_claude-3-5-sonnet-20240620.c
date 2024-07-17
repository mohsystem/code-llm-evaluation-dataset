
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int is_valid_ipv4(const char* ip) {
    int octets[4];
    if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;
        }
    }
    char buf[16];
    sprintf(buf, "%d.%d.%d.%d", octets[0], octets[1], octets[2], octets[3]);
    return strcmp(buf, ip) == 0;
}

int is_valid_ipv6(const char* ip) {
    regex_t regex;
    int reti = regcomp(&regex, "^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$", REG_EXTENDED);
    if (reti) {
        return 0;
    }
    reti = regexec(&regex, ip, 0, NULL, 0);
    regfree(&regex);
    return reti == 0;
}

int main() {
    char ip[46];
    printf("Enter an IP address: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\
")] = 0;

    if (is_valid_ipv4(ip)) {
        printf("Valid IPv4 address\
");
    } else if (is_valid_ipv6(ip)) {
        printf("Valid IPv6 address\
");
    } else {
        printf("Invalid IP address\
");
    }

    return 0;
}
