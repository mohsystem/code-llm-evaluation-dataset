#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cleanPhoneNumber(char* phoneNumber) {
    int i, j;
    for (i = 0, j = 0; i < strlen(phoneNumber); i++) {
        if (isdigit(phoneNumber[i])) {
            phoneNumber[j++] = phoneNumber[i];
        }
    }
    phoneNumber[j] = '\0';
    if (phoneNumber[0] == '1') {
        for (i = 0; i < strlen(phoneNumber); i++) {
            phoneNumber[i] = phoneNumber[i + 1];
        }
    }
}

int main() {
    char phoneNumber[20];
    printf("Enter phone number: ");
    scanf("%19s", phoneNumber);
    cleanPhoneNumber(phoneNumber);
    printf("%s
", phoneNumber);
    return 0;
}