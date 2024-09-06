#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* encrypt(char* text, int key) {
    char* result = strdup(text); 
    for (int i = 0; result[i] != '\0'; i++) {
        if (isalpha(result[i])) {
            char start = islower(result[i]) ? 'a' : 'A';
            result[i] = (char)(((result[i] - start + key) % 26) + start);
        } else if (isdigit(result[i])) {
            result[i] = (char)((((result[i] - '0') + key) % 10) + '0');
        }
    }
    return result;
}

int main() {
    char inputString[] = "Hello, world 123!";
    int encryptionKey = 3;
    char* encryptedString = encrypt(inputString, encryptionKey);
    printf("Encrypted: %s\n", encryptedString);
    free(encryptedString); 
    return 0;
}