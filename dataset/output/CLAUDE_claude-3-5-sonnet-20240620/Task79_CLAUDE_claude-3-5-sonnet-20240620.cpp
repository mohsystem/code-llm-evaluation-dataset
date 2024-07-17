
#include <iostream>
#include <string>
#include <vector>
#include <openssl/aes.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

std::string base64_encode(const std::vector<unsigned char>& input) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, input.data(), input.size());
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    std::string result(bptr->data, bptr->length - 1);
    BIO_free_all(b64);

    return result;
}

std::string encrypt(const std::string& message, const std::string& key) {
    std::vector<unsigned char> iv(AES_BLOCK_SIZE, 0);

    AES_KEY aes_key;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aes_key);

    int padded_len = (message.length() + AES_BLOCK_SIZE) & ~(AES_BLOCK_SIZE - 1);
    std::vector<unsigned char> padded_message(padded_len, 0);
    std::copy(message.begin(), message.end(), padded_message.begin());

    std::vector<unsigned char> encrypted(padded_len);
    AES_cbc_encrypt(padded_message.data(), encrypted.data(), padded_len, &aes_key, iv.data(), AES_ENCRYPT);

    return base64_encode(encrypted);
}

int main() {
    std::string message = "Hello, World!";
    std::string key = "MySecretKey12345";

    std::string encrypted_message = encrypt(message, key);
    std::cout << "Encrypted message: " << encrypted_message << std::endl;

    return 0;
}
