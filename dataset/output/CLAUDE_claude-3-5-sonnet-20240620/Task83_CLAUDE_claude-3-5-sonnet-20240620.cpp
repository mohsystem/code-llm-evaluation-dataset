
#include <iostream>
#include <string>
#include <vector>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

std::string base64_encode(const std::vector<unsigned char>& input) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(bio, input.data(), input.size());
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    return std::string(bufferPtr->data, bufferPtr->length);
}

std::string encrypt_key(const std::string& key) {
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char aes_key[32];
    RAND_bytes(iv, AES_BLOCK_SIZE);
    RAND_bytes(aes_key, 32);

    AES_KEY aes;
    AES_set_encrypt_key(aes_key, 256, &aes);

    std::vector<unsigned char> padded_key(key.begin(), key.end());
    size_t padding = AES_BLOCK_SIZE - (padded_key.size() % AES_BLOCK_SIZE);
    padded_key.insert(padded_key.end(), padding, static_cast<unsigned char>(padding));

    std::vector<unsigned char> encrypted(iv, iv + AES_BLOCK_SIZE);
    encrypted.resize(encrypted.size() + padded_key.size());

    unsigned char* out_ptr = encrypted.data() + AES_BLOCK_SIZE;
    const unsigned char* in_ptr = padded_key.data();
    size_t remaining = padded_key.size();

    while (remaining > 0) {
        AES_cbc_encrypt(in_ptr, out_ptr, AES_BLOCK_SIZE, &aes, iv, AES_ENCRYPT);
        in_ptr += AES_BLOCK_SIZE;
        out_ptr += AES_BLOCK_SIZE;
        remaining -= AES_BLOCK_SIZE;
    }

    return base64_encode(encrypted);
}

int main() {
    std::string key_to_encrypt = "MySecretKey123456";
    std::string encrypted_key = encrypt_key(key_to_encrypt);
    std::cout << "Encrypted key: " << encrypted_key << std::endl;
    return 0;
}
