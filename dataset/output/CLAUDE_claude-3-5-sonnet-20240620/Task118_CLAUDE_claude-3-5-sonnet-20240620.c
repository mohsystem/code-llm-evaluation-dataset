
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int validateIP(const char* ip) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, "^([0-9]{1,3}\\\\.){3}[0-9]{1,3}$", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\\n");
        exit(1);
    }

    reti = regexec(&regex, ip, 0, NULL, 0);
    if (!reti) {
        char* token = strtok((char*)ip, ".");
        while (token != NULL) {
            int value = atoi(token);
            if (value < 0 || value > 255) {
                regfree(&regex);
                return 0;
            }
            token = strtok(NULL, ".");
        }
        regfree(&regex);
        return 1;
    } else if (reti == REG_NOMATCH) {
        regfree(&regex);
        return 0;
    } else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\\n", msgbuf);
        exit(1);
    }
}

void processIP(const char* ip) {
    if (validateIP(ip)) {
        int firstOctet = atoi(strtok((char*)ip, "."));
        char* classType;
        if (firstOctet >= 1 && firstOctet <= 126) {
            classType = "A";
        } else if (firstOctet >= 128 && firstOctet <= 191) {
            classType = "B";
        } else if (firstOctet >= 192 && firstOctet <= 223) {
            classType = "C";
        } else if (firstOctet >= 224 && firstOctet <= 239) {
            classType = "D";
        } else if (firstOctet >= 240 && firstOctet <= 255) {
            classType = "E";
        }
        printf("Valid IP address. Class: %s\\n", classType);
    } else {
        printf("Invalid IP address\\n");
    }
}

int main() {
    char ip[16];
    printf("Enter an IP address: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\\n")] = 0;  // Remove newline
    processIP(ip);
    return 0;
}
