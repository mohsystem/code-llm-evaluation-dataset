#include <stdio.h>
#include <string.h>

int main() {
    char inputStr1[100], inputStr2[100], result[200];
    printf("Enter first string: ");
    fgets(inputStr1, sizeof(inputStr1), stdin);
    printf("Enter second string: ");
    fgets(inputStr2, sizeof(inputStr2), stdin);
    
    // Removing the newline character from strings if present
    inputStr1[strcspn(inputStr1, "\n")] = 0;
    inputStr2[strcspn(inputStr2, "\n")] = 0;

    strcpy(result, inputStr1);
    strcat(result, inputStr2);
    printf("Concatenated result: %s\n", result);
    return 0;
}