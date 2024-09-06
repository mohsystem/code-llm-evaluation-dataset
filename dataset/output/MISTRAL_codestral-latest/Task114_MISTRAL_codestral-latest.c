// C
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, ";
    char str2[] = "World!";

    // Copying a string
    char str3[20];
    strcpy(str3, str1);
    printf("Copied string: %s\n", str3);

    // Concatenating strings
    char str4[30];
    strcpy(str4, str1);
    strcat(str4, str2);
    printf("Concatenated string: %s\n", str4);

    // Manipulating strings
    char str5[30];
    strcpy(str5, str4);
    char *pos = strstr(str5, "World");
    if (pos != NULL)
        strncpy(pos, "C", 1);
    printf("Manipulated string: %s\n", str5);

    return 0;
}