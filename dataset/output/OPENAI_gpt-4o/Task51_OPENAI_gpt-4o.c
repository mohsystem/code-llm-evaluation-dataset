#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], char result[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            result[i] = (text[i] + 1 - 'A') % 26 + 'A';
        } else if (islower(text[i])) {
            result[i] = (text[i] + 1 - 'a') % 26 + 'a';
        } else {
            result[i] = text[i];
        }
    }
}

int main() {
    char inputText[] = "HelloWorld";
    char encryptedText[100];
    
    encrypt(inputText, encryptedText);
    printf("%s\n", encryptedText);
    
    return 0;
}