#include <regex.h>
#include <string.h>
#include <stdlib.h>

char* cleanPhoneNumber(const char* phoneNumber) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    reti = regcomp(&regex, "\\D", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex
");
        exit(1);
    }

    char* cleanedNumber = malloc(strlen(phoneNumber) + 1);
    reti = regexec(&regex, phoneNumber, 0, NULL, 0);
    if (!reti) {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s
", msgbuf);
        exit(1);
    }

    regfree(&regex);

    if (cleanedNumber[0] == '1') {
        memmove(cleanedNumber, cleanedNumber + 1, strlen(cleanedNumber));
    }

    return cleanedNumber;
}