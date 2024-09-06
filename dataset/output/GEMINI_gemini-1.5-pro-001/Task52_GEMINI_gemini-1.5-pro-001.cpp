// This example requires OpenSSL library installed and linked to the project
#include <iostream>
#include <fstream>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

using namespace std;

// Function to generate a random encryption key
vector<unsigned char> generateKey() {
    vector<unsigned char> key(AES_BLOCK_SIZE);
    RAND_bytes(key.data(), key.size());
    return key;
}

// Function to encrypt the file
bool encryptFile(const string& inputFile, const string& outputFile, const vector<unsigned char>& key) {
    // Create a cipher context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return false;

    // Set up the encryption parameters
    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), nullptr, key.data(), nullptr) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // Open the input and output files
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);
    if (!inFile || !outFile) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // Read and encrypt data from the input file
    const size_t bufferSize = 1024;
    unsigned char inBuffer[bufferSize];
    unsigned char outBuffer[bufferSize + AES_BLOCK_SIZE]; // Output buffer may be larger due to padding
    int outLen, totalLen = 0;
    while (inFile.read(reinterpret_cast<char*>(inBuffer), bufferSize)) {
        int len = inFile.gcount();
        if (EVP_EncryptUpdate(ctx, outBuffer, &outLen, inBuffer, len) != 1) {
            EVP_CIPHER_CTX_free(ctx);
            return false;
        }
        outFile.write(reinterpret_cast<char*>(outBuffer), outLen);
        totalLen += outLen;
    }

    // Finalize the encryption process
    if (EVP_EncryptFinal_ex(ctx, outBuffer, &outLen) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    outFile.write(reinterpret_cast<char*>(outBuffer), outLen);
    totalLen += outLen;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return true;
}

// Function to decrypt the file
bool decryptFile(const string& inputFile, const string& outputFile, const vector<unsigned char>& key) {
    // Create a cipher context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return false;

    // Set up the decryption parameters
    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), nullptr, key.data(), nullptr) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // Open the input and output files
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);
    if (!inFile || !outFile) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // Read and decrypt data from the input file
    const size_t bufferSize = 1024;
    unsigned char inBuffer[bufferSize];
    unsigned char outBuffer[bufferSize];
    int outLen, totalLen = 0;
    while (inFile.read(reinterpret_cast<char*>(inBuffer), bufferSize)) {
        int len = inFile.gcount();
        if (EVP_DecryptUpdate(ctx, outBuffer, &outLen, inBuffer, len) != 1) {
            EVP_CIPHER_CTX_free(ctx);
            return false;
        }
        outFile.write(reinterpret_cast<char*>(outBuffer), outLen);
        totalLen += outLen;
    }

    // Finalize the decryption process
    if (EVP_DecryptFinal_ex(ctx, outBuffer, &outLen) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    outFile.write(reinterpret_cast<char*>(outBuffer), outLen);
    totalLen += outLen;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return true;
}

int main() {
    // Generate a random encryption key
    vector<unsigned char> key = generateKey();

    // File paths
    string inputFile = "test.txt";
    string encryptedFile = "encrypted.txt";
    string decryptedFile = "decrypted.txt";

    // Encrypt the file
    if (encryptFile(inputFile, encryptedFile, key)) {
        cout << "File encrypted successfully." << endl;
    } else {
        cerr << "Encryption failed." << endl;
        return 1;
    }

    // Decrypt the file
    if (decryptFile(encryptedFile, decryptedFile, key)) {
        cout << "File decrypted successfully." << endl;
    } else {
        cerr << "Decryption failed." << endl;
        return 1;
    }

    return 0;
}