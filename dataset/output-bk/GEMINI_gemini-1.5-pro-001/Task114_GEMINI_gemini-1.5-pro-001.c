#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100], copiedString[100], concatenatedString[200], reversedString[100];
    int i, j;

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Copy the string
    strcpy(copiedString, inputString);

    // Concatenate the string with itself
    strcpy(concatenatedString, inputString);
    strcat(concatenatedString, inputString);

    // Reverse the string
    j = 0;
    for (i = strlen(inputString) - 2; i >= 0; i--) {
        reversedString[j++] = inputString[i];
    }
    reversedString[j] = '\0';

    // Convert the string to uppercase
    for (i = 0; inputString[i]; i++) {
        inputString[i] = toupper(inputString[i]);
    }

    // Print the results
    printf("Copied string: %s", copiedString);
    printf("Concatenated string: %s", concatenatedString);
    printf("Reversed string: %s", reversedString);
    printf("Uppercase string: %s
", inputString);

    return 0;
}