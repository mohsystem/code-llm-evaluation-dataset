#include <stdio.h>
#include <string.h>

int main() {
    // String declaration and initialization
    char str1[] = "Hello";
    char str2[] = "World";
    char concatenatedString[100];

    // String concatenation
    strcpy(concatenatedString, str1);
    strcat(concatenatedString, " ");
    strcat(concatenatedString, str2);
    printf("Concatenated String: %s\n", concatenatedString);

    // String copying
    char copiedString[100];
    strcpy(copiedString, str1);
    printf("Copied String: %s\n", copiedString);

    // String length
    int length = strlen(concatenatedString);
    printf("Length of Concatenated String: %d\n", length);

    // String manipulation - uppercase
    for (int i = 0; concatenatedString[i] != '\0'; i++) {
        concatenatedString[i] = toupper(concatenatedString[i]);
    }
    printf("Uppercase String: %s\n", concatenatedString);

    // String manipulation - lowercase
    for (int i = 0; concatenatedString[i] != '\0'; i++) {
        concatenatedString[i] = tolower(concatenatedString[i]);
    }
    printf("Lowercase String: %s\n", concatenatedString);

    // Substring extraction
    char substring[6];
    strncpy(substring, concatenatedString, 5);
    substring[5] = '\0'; // Add null terminator
    printf("Substring: %s\n", substring);

    return 0;
}