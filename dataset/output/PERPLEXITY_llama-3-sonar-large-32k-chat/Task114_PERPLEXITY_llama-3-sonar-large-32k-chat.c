code here:
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[10] = "Hello";
    char s2[10] = "World";
    printf("Original Strings:\n");
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    // Copying a string
    char s3[10];
    strcpy(s3, s1);
    printf("\nCopied String:\n");
    printf("s3: %s\n", s3);

    // Concatenating strings
    char s4[20];
    strcpy(s4, s1);
    strcat(s4, " ");
    strcat(s4, s2);
    printf("\nConcatenated String:\n");
    printf("s4: %s\n", s4);

    // Manipulating strings (upper case)
    char s5[10];
    strcpy(s5, s1);
    for(int i = 0; i < strlen(s5); i++) {
        s5[i] = toupper(s5[i]);
    }
    printf("\nUpper Case String:\n");
    printf("s5: %s\n", s5);

    // Manipulating strings (lower case)
    char s6[10];
    strcpy(s6, s2);
    for(int i = 0; i < strlen(s6); i++) {
        s6[i] = tolower(s6[i]);
    }
    printf("\nLower Case String:\n");
    printf("s6: %s\n", s6);

    return 0;
}