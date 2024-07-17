#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cleanPhoneNumber(const char *phone, char *out) {
    int j = 0;
    for (int i = 0; phone[i] != '\0'; ++i) {
        if (isdigit(phone[i])) {
            out[j++] = phone[i];
        }
    }
    out[j] = '\0';

    if (out[0] == '1' && strlen(out) == 11) {
        memmove(out, out + 1, strlen(out));
    }
}

int main() {
    char phone_numbers[4][20] = {
        "+1 (613)-995-0253",
        "613-995-0253",
        "1 613 995 0253",
        "613.995.0253"
    };

    char cleaned_number[15];

    for (int i = 0; i < 4; ++i) {
        cleanPhoneNumber(phone_numbers[i], cleaned_number);
        printf("%s
", cleaned_number);
    }

    return 0;
}