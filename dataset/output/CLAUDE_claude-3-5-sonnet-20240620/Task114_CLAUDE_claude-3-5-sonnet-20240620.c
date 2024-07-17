
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char copy[20], concat[20], upper[20], sub[20], replace[20];

    // Copy
    strcpy(copy, str1);

    // Concatenate
    sprintf(concat, "%s %s", str1, str2);

    // Manipulate
    strcpy(upper, concat);
    for (int i = 0; upper[i]; i++) {
        upper[i] = toupper(upper[i]);
    }

    strncpy(sub, concat, 5);
    sub[5] = \'\\0\';

    strcpy(replace, concat);
    for (int i = 0; replace[i]; i++) {
        if (replace[i] == \'o\') replace[i] = \'0\';
    }

    printf("Original: %s, %s\
", str1, str2);
    printf("Copy: %s\
", copy);
    printf("Concatenated: %s\
", concat);
    printf("Uppercase: %s\
", upper);
    printf("Substring: %s\
", sub);
    printf("Replaced: %s\
", replace);

    return 0;
}
