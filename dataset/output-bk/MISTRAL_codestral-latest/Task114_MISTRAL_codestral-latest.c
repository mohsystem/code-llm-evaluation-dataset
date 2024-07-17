#include <stdio.h>
#include <string.h>

int main() {
    // Copying a string
    char str1[] = "Hello";
    char str2[10];
    strcpy(str2, str1);
    printf("Copied string: %s
", str2);

    // Concatenating strings
    char str3[] = " World";
    strcat(str1, str3);
    printf("Concatenated string: %s
", str1);

    // Manipulating strings
    char str4[] = "C Programming";
    printf("Length of the string: %lu
", strlen(str4));

    char *substr = strchr(str4, ' ');
    printf("Substring: %s
", substr);

    for (int i = 0; str4[i]; i++) {
        str4[i] = toupper(str4[i]);
    }
    printf("Uppercase: %s
", str4);

    for (int i = 0; str4[i]; i++) {
        str4[i] = tolower(str4[i]);
    }
    printf("Lowercase: %s
", str4);

    return 0;
}