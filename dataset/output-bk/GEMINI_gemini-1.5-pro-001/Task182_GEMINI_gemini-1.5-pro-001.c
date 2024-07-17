#include <stdio.h>
#include <string.h>

void clean_phone_number(char *phone_number) {
    char cleaned_number[11];
    int j = 0;
    for (int i = 0; phone_number[i] != '\0'; i++) {
        if (phone_number[i] >= '0' && phone_number[i] <= '9') {
            cleaned_number[j++] = phone_number[i];
        }
    }
    cleaned_number[j] = '\0';
    if (strlen(cleaned_number) == 11 && cleaned_number[0] == '1') {
        strcpy(phone_number, cleaned_number + 1);
    } else {
        strcpy(phone_number, cleaned_number);
    }
}

int main() {
    char phone_numbers[][20] = {
        "+1 (613)-995-0253",
        "613-995-0253",
        "1 613 995 0253",
        "613.995.0253"
    };

    for (int i = 0; i < sizeof(phone_numbers) / sizeof(phone_numbers[0]); i++) {
        clean_phone_number(phone_numbers[i]);
        printf("%s
", phone_numbers[i]);
    }

    return 0;
}