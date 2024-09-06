#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int multiplicativeInverse(int e, int phi) {
    int x = 0;
    int y = 1;
    int a = phi;
    int b = e;

    while (b != 0) {
        int q = a / b;
        int temp = b;
        b = a % b;
        a = temp;
        temp = x;
        x = y - q * x;
        y = temp;
    }

    if (y < 0) {
        y += phi;
    }

    return y;
}

void generateKeyPair(int p, int q, int* publicKey, int* privateKey) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    srand(time(NULL));
    int e = rand() % phi + 1;
    while (gcd(e, phi) != 1) {
        e = rand() % phi + 1;
    }

    int d = multiplicativeInverse(e, phi);
    *publicKey = e;
    *privateKey = d;
}

void encrypt(int publicKey, int n, char* plaintext, int* ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = pow(plaintext[i], publicKey) % n;
    }
}

void decrypt(int privateKey, int n, int* ciphertext, char* plaintext) {
    for (int i = 0; ciphertext[i] != 0; i++) {
        plaintext[i] = pow(ciphertext[i], privateKey) % n;
    }
    plaintext[i] = '\0';
}

int main() {
    int p = 61;
    int q = 53;
    int publicKey, privateKey;
    generateKeyPair(p, q, &publicKey, &privateKey);
    printf("Public Key: %d, %d\n", publicKey, p * q);
    printf("Private Key: %d, %d\n", privateKey, p * q);

    char message[] = "Hello, World!";
    int encryptedMessage[sizeof(message) / sizeof(message[0])];
    encrypt(publicKey, p * q, message, encryptedMessage);
    printf("Encrypted Message: ");
    for (int i = 0; encryptedMessage[i] != 0; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");

    char decryptedMessage[sizeof(message) / sizeof(message[0])];
    decrypt(privateKey, p * q, encryptedMessage, decryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}