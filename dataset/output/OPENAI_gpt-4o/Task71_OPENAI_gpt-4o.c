#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidInteger(char *str) {
    if (*str == '-' || *str == '+') str++;
    if(*str == '\0') return false;

    while (*str) {
        if (!isdigit(*str)) return false;
        str++;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a string to convert.\n");
    } else {
        char *inputStr = argv[1];
        if (isValidInteger(inputStr)) {
            int convertedInt = atoi(inputStr);
            printf("Converted integer: %d\n", convertedInt);
        } else {
            printf("Invalid input: Not a valid integer.\n");
        }
    }
    return 0;
}