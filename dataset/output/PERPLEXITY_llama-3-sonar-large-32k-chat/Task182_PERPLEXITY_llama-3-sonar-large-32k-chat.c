#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cleanPhoneNumber(char* phoneNumber) {
    int i, j;
    for (i = 0, j = 0; phoneNumber[i] != '\0'; i++) {
        if (isdigit(phoneNumber[i])) {
            phoneNumber[j++] = phoneNumber[i];
        }
    }
    phoneNumber[j] = '\0';
    if (phoneNumber[0] == '1' && strlen(phoneNumber) > 1) {
        memmove(phoneNumber, phoneNumber + 1, strlen(phoneNumber));
    }
}

int main() {
    char phoneNumber1[] = "+1 (613)-995-0253";
    char phoneNumber2[] = "613-995-0253";
    char phoneNumber3[] = "1 613 995 0253";
    char phoneNumber4[] = "613.995.0253";

    cleanPhoneNumber(phoneNumber1);
    cleanPhoneNumber(phoneNumber2);
    cleanPhoneNumber(phoneNumber3);
    cleanPhoneNumber(phoneNumber4);

    printf("%s\n", phoneNumber1);
    printf("%s\n", phoneNumber2);
    printf("%s\n", phoneNumber3);
    printf("%s\n", phoneNumber4);

    return 0;
}