#include <stdio.h>
#include <string.h>

char *encrypt(char *message);

int main() {
    char message[100];
    printf("Enter a string to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "
")] = 0; // Remove trailing newline

    char *encryptedMessage = encrypt(message);
    printf("Encrypted message: %s
", encryptedMessage);

    return 0;
}

char *encrypt(char *message) {
    int length = strlen(message);
    char *encrypted = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        encrypted[i] = message[i] + 3; // Simple Caesar cipher with a shift of 3
    }
    encrypted[length] = '\0';
    return encrypted;
}