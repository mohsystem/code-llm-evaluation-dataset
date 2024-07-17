#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";
    
    // Copying a string
    char str3[20];
    strcpy(str3, str1);
    printf("Copied string: %s
", str3);
    
    // Concatenating strings
    char str4[40];
    strcpy(str4, str1);
    strcat(str4, " ");
    strcat(str4, str2);
    printf("Concatenated string: %s
", str4);
    
    // Manipulating strings (upper case)
    for(int i = 0; i < strlen(str1); i++) {
        str1[i] = toupper(str1[i]);
    }
    printf("Upper case string: %s
", str1);
    
    // Manipulating strings (lower case)
    for(int i = 0; i < strlen(str2); i++) {
        str2[i] = tolower(str2[i]);
    }
    printf("Lower case string: %s
", str2);
    
    return 0;
}