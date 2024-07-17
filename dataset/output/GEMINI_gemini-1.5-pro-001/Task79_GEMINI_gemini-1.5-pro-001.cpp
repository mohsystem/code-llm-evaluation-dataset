#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/rand.h>

using namespace std;

string encrypt(const string& plaintext, const string& key) {
    // Generate a cipher context for encryption
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        cerr << "Error creating cipher context" << endl;
        return "";
    }

    // Set up the encryption parameters
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (const unsigned char*)key.c_str(), NULL) != 1) {
        cerr << "Error initializing encryption" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    // Allocate memory for ciphertext
    int ciphertext_len = plaintext.length() + EVP_CIPHER_block_size(EVP_aes_256_cbc());
    unsigned char* ciphertext = (unsigned char*)malloc(ciphertext_len);
    if (!ciphertext) {
        cerr << "Error allocating memory for ciphertext" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    // Encrypt the plaintext
    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, (const unsigned char*)plaintext.c_str(), plaintext.length()) != 1) {
        cerr << "Error encrypting data" << endl;
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return "";
    }
    ciphertext_len = len;

    // Finalize the encryption process
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) {
        cerr << "Error finalizing encryption" << endl;
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return "";
    }
    ciphertext_len += len;

    // Convert the ciphertext to a string
    string ciphertext_str((char*)ciphertext, ciphertext_len);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);

    return ciphertext_str;
}

int main() {
    string message = "This is a secret message";
    string key = "This is a secret key";

    string encryptedMessage = encrypt(message, key);
    cout << "Encrypted: " << encryptedMessage << endl;

    return 0;
}