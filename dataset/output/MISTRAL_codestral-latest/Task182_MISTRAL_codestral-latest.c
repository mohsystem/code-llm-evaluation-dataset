#include <regex.h>
#include <string.h>
#include <stdlib.h>

char* cleanPhoneNumber(const char* phoneNumber) {
    regex_t regex;
    regcomp(&regex, "\\D", REG_EXTENDED);
    char* cleanedNumber = malloc(strlen(phoneNumber) + 1);
    regsub(&regex, "", phoneNumber, 0, cleanedNumber, strlen(phoneNumber) + 1);
    regfree(&regex);
    if (cleanedNumber[0] == '1') {
        memmove(cleanedNumber, cleanedNumber + 1, strlen(cleanedNumber));
    }
    return cleanedNumber;
}