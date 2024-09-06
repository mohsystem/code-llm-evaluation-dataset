// C
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(const char* message, int key, char* cipher) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char shifted = isupper(message[i]) ? 'A' : 'a';
            cipher[i] = (char) ((message[i] - shifted + key) % 26 + shifted);
        } else {
            cipher[i] = message[i];
        }
    }
    cipher[strlen(message)] = '\0';
}

int main() {
    const char* message = "HELLO WORLD";
    int key = 3;
    char encryptedMessage[strlen(message) + 1];
    encrypt(message, key, encryptedMessage);
    printf("%s\n", encryptedMessage);
    return 0;
}