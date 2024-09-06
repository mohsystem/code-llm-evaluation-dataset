code here:
// Note: C does not have a built-in map or string class, so we'll use arrays and manual indexing
#include <stdio.h>

void createCipher(int key, char cipher[][2]) {
    for (int i = 0; i < 26; i++) {
        cipher[i][0] = (char) (65 + i);
        cipher[i][1] = (char) (65 + (i + key) % 26);
        cipher[i+26][0] = (char) (97 + i);
        cipher[i+26][1] = (char) (97 + (i + key) % 26);
    }
}

void encryptMessage(char message[], int key, char cipher[][2]) {
    for (int i = 0; message[i] != '\0'; i++) {
        for (int j = 0; j < 52; j++) {
            if (message[i] == cipher[j][0]) {
                message[i] = cipher[j][1];
                break;
            }
        }
    }
}

int main() {
    int key = 3;
    char message[] = "Hello, World!";
    char cipher[52][2];
    createCipher(key, cipher);
    encryptMessage(message, key, cipher);
    printf("Original Message: %s\n", "Hello, World!");
    printf("Encrypted Message: %s\n", message);
    return 0;
}