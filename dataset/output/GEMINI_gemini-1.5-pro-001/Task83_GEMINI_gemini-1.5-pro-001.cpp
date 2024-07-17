#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

using namespace std;

int main() {
    // Generate a random encryption key
    unsigned char key[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);

    // Generate a random initialization vector (IV)
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // Create a cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        cerr << "Error creating cipher context" << endl;
        return 1;
    }

    // Initialize the cipher context for encryption
    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1) {
        cerr << "Error initializing cipher context" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }

    // Encrypt the key
    int ciphertext_len = 0;
    int len;
    unsigned char ciphertext[AES_BLOCK_SIZE * 2];
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, key, AES_BLOCK_SIZE) != 1) {
        cerr << "Error encrypting data" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }
    ciphertext_len += len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &len) != 1) {
        cerr << "Error finalizing encryption" << endl;
        EVP_CIPHER_CTX_free(ctx);
        return 1;
    }
    ciphertext_len += len;

    // Convert the encrypted key and IV to Base64
    BIO *bio = BIO_new(BIO_s_mem());
    BIO *b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);

    BIO_write(bio, ciphertext, ciphertext_len);
    BIO_write(bio, "
", 1);
    BIO_write(bio, iv, AES_BLOCK_SIZE);
    BIO_flush(bio);

    char *base64_data;
    long base64_len = BIO_get_mem_data(bio, &base64_data);
    string encoded_key(base64_data, base64_len - 1); // Exclude the newline

    // Print the encoded key and IV
    cout << "Encrypted Key (Base64): " << encoded_key.substr(0, encoded_key.find("
")) << endl;
    cout << "IV (Base64): " << encoded_key.substr(encoded_key.find("
") + 1) << endl;

    // Clean up
    BIO_free_all(bio);
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}