
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 51

int getValidNumber(int min, int max) {
    int number;
    char input[100];
    char *endptr;

    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\
");
            exit(1);
        }

        number = strtol(input, &endptr, 10);

        if (endptr == input || *endptr != \'\
\') {
            printf("Invalid input. Please enter a number: ");
        } else if (number < min || number > max) {
            printf("Please enter a number between %d and %d: ", min, max);
        } else {
            return number;
        }
    }
}

void getValidString(char *buffer, int maxLength) {
    while (1) {
        if (fgets(buffer, maxLength, stdin) == NULL) {
            printf("Error reading input.\
");
            exit(1);
        }

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == \'\
\') {
            buffer[len - 1] = \'\\0\';
            len--;
        }

        if (len > 0 && len < maxLength - 1) {
            return;
        } else {
            printf("Please enter a non-empty string with max %d characters: ", maxLength - 1);
        }
    }
}

int main() {
    int number;
    char name[MAX_NAME_LENGTH];

    printf("Enter a number between 1 and 100: ");
    number = getValidNumber(1, 100);

    printf("Enter your name (max 50 characters): ");
    getValidString(name, MAX_NAME_LENGTH);

    printf("Hello, %s!\
", name);
    printf("Your number squared is: %d\
", number * number);
    printf("Your number cubed is: %d\
", number * number * number);

    return 0;
}
