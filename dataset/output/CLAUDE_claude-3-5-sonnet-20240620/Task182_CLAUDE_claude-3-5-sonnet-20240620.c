
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20

char* clean_phone_number(const char* phone) {
    char* cleaned = malloc(MAX_LENGTH * sizeof(char));
    int j = 0;

    // Remove all non-digit characters
    for (int i = 0; phone[i] != \'\\0\'; i++) {
        if (isdigit(phone[i])) {
            cleaned[j++] = phone[i];
        }
    }
    cleaned[j] = \'\\0\';

    // Remove country code if present
    if (strlen(cleaned) == 11 && cleaned[0] == \'1\') {
        memmove(cleaned, cleaned + 1, strlen(cleaned));
    }

    // Check if the number is valid
    if (strlen(cleaned) != 10 || cleaned[0] < \'2\' || cleaned[0] > \'9\') {
        free(cleaned);
        return NULL;
    }

    return cleaned;
}

int main() {
    const char* test_numbers[] = {
        "+1 (613)-995-0253",
        "613-995-0253",
        "1 613 995 0253",
        "613.995.0253"
    };
    int num_tests = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < num_tests; i++) {
        char* result = clean_phone_number(test_numbers[i]);
        if (result) {
            printf("%s\
", result);
            free(result);
        } else {
            printf("Error: Invalid phone number\
");
        }
    }

    return 0;
}
