#include <fstream>
#include <iostream>

#define BLOCK_SIZE 16

void encrypt(const char* fileToEncrypt, const char* encryptedFile) {
    std::ifstream fis(fileToEncrypt, std::ios::binary);
    std::ofstream fos(encryptedFile, std::ios::binary);
    char buffer[BLOCK_SIZE];
    while (fis.read(buffer, BLOCK_SIZE)) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= 0x17; // simple XOR encryption
        }
        fos.write(buffer, BLOCK_SIZE);
    }
    fis.close();
    fos.close();
}

void decrypt(const char* encryptedFile, const char* decryptedFile) {
    std::ifstream fis(encryptedFile, std::ios::binary);
    std::ofstream fos(decryptedFile, std::ios::binary);
    char buffer[BLOCK_SIZE];
    while (fis.read(buffer, BLOCK_SIZE)) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= 0x17; // simple XOR decryption
        }
        fos.write(buffer, BLOCK_SIZE);
    }
    fis.close();
    fos.close();
}

int main() {
    const char* fileToEncrypt = "input.txt";
    const char* encryptedFile = "encrypted.txt";
    const char* decryptedFile = "decrypted.txt";

    encrypt(fileToEncrypt, encryptedFile);
    decrypt(encryptedFile, decryptedFile);

    return 0;
}