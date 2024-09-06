
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PHONE_LENGTH 20

char* clean_phone_number(const char* phone) {
    char* digits = malloc(MAX_PHONE_LENGTH * sizeof(char));
    int j = 0;
    
    for (int i = 0; phone[i] != '\\0'; i++) {
        if (isdigit(phone[i])) {
            digits[j++] = phone[i];
        }
    }
    digits[j] = '\\0';
    
    if (strlen(digits) == 11 && digits[0] == '1') {
        memmove(digits, digits + 1, strlen(digits));
    } else if (strlen(digits) != 10) {
        free(digits);
        return NULL;
    }
    
    return digits;
}

int main() {
    const char* phone_numbers[] = {
        "+1 (613)-995-0253",
        "613-995-0253",
        "1 613 995 0253",
        "613.995.0253"
    };
    
    for (int i = 0; i < 4; i++) {
        char* cleaned = clean_phone_number(phone_numbers[i]);
        if (cleaned) {
            printf("%s\\n", cleaned);
            free(cleaned);
        } else {
            printf("Error: Invalid phone number\\n");
        }
    }
    
    return 0;
}
