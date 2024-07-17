#include <stdio.h>
#include <string.h>

char* createCipher(char* secretKey) {
    static char cipher[100];
    strcpy(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    strcat(cipher, secretKey);
    return cipher;
}

char* encryptMessage(char* message, char* cipher) {
    static char encryptedMessage[100];
    for (int i = 0; i < strlen(message); i++) {
        encryptedMessage[i] = message[i] + cipher[i % strlen(cipher)];
    }
    encryptedMessage[strlen(message)] = '\0';
    return encryptedMessage;
}

int main() {
    char message[] = "Hello, World!";
    char secretKey[] = "mySecretKey";
    char* cipher = createCipher(secretKey);
    char* encryptedMessage = encryptMessage(message, cipher);
    printf("Encrypted Message: %s
", encryptedMessage);
    return 0;
}