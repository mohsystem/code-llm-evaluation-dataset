#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void encrypt(char* fileToEncrypt, char* encryptedFile) {
    FILE* fis = fopen(fileToEncrypt, "rb");
    FILE* fos = fopen(encryptedFile, "wb");
    unsigned char buffer[BLOCK_SIZE];
    int bytesRead;
    while ((bytesRead = fread(buffer, 1, BLOCK_SIZE, fis)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= 0x17; // simple XOR encryption
        }
        fwrite(buffer, 1, bytesRead, fos);
    }
    fclose(fis);
    fclose(fos);
}

void decrypt(char* encryptedFile, char* decryptedFile) {
    FILE* fis = fopen(encryptedFile, "rb");
    FILE* fos = fopen(decryptedFile, "wb");
    unsigned char buffer[BLOCK_SIZE];
    int bytesRead;
    while ((bytesRead = fread(buffer, 1, BLOCK_SIZE, fis)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= 0x17; // simple XOR decryption
        }
        fwrite(buffer, 1, bytesRead, fos);
    }
    fclose(fis);
    fclose(fos);
}

int main() {
    char fileToEncrypt[] = "input.txt";
    char encryptedFile[] = "encrypted.txt";
    char decryptedFile[] = "decrypted.txt";

    encrypt(fileToEncrypt, encryptedFile);
    decrypt(encryptedFile, decryptedFile);

    return 0;
}