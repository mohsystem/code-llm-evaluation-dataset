#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

using namespace std;

int main() {
    // Set key and IV (replace with your own secure values)
    unsigned char key[AES_BLOCK_SIZE] = "YourSecretKeyHere"; 
    unsigned char iv[AES_BLOCK_SIZE] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    // Input data
    string plaintext = "This is some data to encrypt.";

    // Padding
    int plaintext_len = plaintext.length();
    int padding_len = AES_BLOCK_SIZE - (plaintext_len % AES_BLOCK_SIZE);
    plaintext.append(padding_len, (char)padding_len);

    // Encrypt
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len = 0;
    unsigned char ciphertext[1024];

    if(!(ctx = EVP_CIPHER_CTX_new())) 
        return 1;

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) 
        return 1;

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char*)plaintext.c_str(), plaintext.length())) 
        return 1;
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) 
        return 1;
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    // Convert ciphertext to Base64
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, ciphertext, ciphertext_len);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);

    string base64_ciphertext(bufferPtr->data, bufferPtr->length - 1); // Exclude newline

    BIO_free_all(bio);

    // Output Base64 encoded ciphertext
    cout << base64_ciphertext << endl;

    return 0;
}