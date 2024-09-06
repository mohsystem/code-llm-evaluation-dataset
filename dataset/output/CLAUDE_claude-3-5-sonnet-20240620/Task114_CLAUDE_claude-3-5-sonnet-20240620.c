
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void string_operations() {
    // String copy
    char original[] = "Hello, World!";
    char copied[MAX_LENGTH];
    strcpy(copied, original);
    printf("Original: %s\\n", original);
    printf("Copied: %s\\n", copied);

    // String concatenation
    char str1[] = "C ";
    char str2[] = "is awesome!";
    char concatenated[MAX_LENGTH];
    strcpy(concatenated, str1);
    strcat(concatenated, str2);
    printf("Concatenated: %s\\n", concatenated);

    // String manipulation
    char text[] = "   C Programming   ";
    char stripped[MAX_LENGTH];
    char upper[MAX_LENGTH];
    char lower[MAX_LENGTH];
    char replaced[MAX_LENGTH];

    // Strip
    int start = 0, end = strlen(text) - 1;
    while (isspace(text[start])) start++;
    while (end > start && isspace(text[end])) end--;
    strncpy(stripped, text + start, end - start + 1);
    stripped[end - start + 1] = '\\0';

    // Uppercase and Lowercase
    strcpy(upper, text);
    strcpy(lower, text);
    for (int i = 0; text[i]; i++) {
        upper[i] = toupper(text[i]);
        lower[i] = tolower(text[i]);
    }

    // Replace
    strcpy(replaced, text);
    char *pos = strstr(replaced, "C");
    if (pos != NULL) {
        memmove(pos + 4, pos + 1, strlen(pos));
        memcpy(pos, "Java", 4);
    }

    printf("Stripped: '%s'\\n", stripped);
    printf("Uppercase: %s\\n", upper);
    printf("Lowercase: %s\\n", lower);
    printf("Replaced: %s\\n", replaced);
}

int main() {
    string_operations();
    return 0;
}
