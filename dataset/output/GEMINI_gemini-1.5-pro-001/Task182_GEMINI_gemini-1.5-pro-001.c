#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clean_phone_number(char *phone_number) {
    char cleaned_number[11];
    int j = 0;
    for (int i = 0; phone_number[i] != '\0'; i++) {
        if (isdigit(phone_number[i])) {
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
        "613.995.0253",
        "123456789012"  // Invalid phone number
    };
    int num_numbers = sizeof(phone_numbers) / sizeof(phone_numbers[0]);

    for (int i = 0; i < num_numbers; i++) {
        char original_number[20];
        strcpy(original_number, phone_numbers[i]);
        clean_phone_number(phone_numbers[i]);
        if (strlen(phone_numbers[i]) == 10) {
            printf("Original: %s -> Cleaned: %s\n", original_number, phone_numbers[i]);
        } else {
            printf("Invalid phone number: %s\n", original_number);
        }
    }

    return 0;
}