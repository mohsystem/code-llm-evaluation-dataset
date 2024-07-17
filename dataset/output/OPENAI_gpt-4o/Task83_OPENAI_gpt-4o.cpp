#include <openssl/evp.h>
#include <openssl/rand.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>

std::string base64_encode(const std::string &in) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    BIO_write(bio, in.data(), in.size());
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);

    std::string ret(bufferPtr->data, bufferPtr->length);
    BIO_free_all(bio);
    return ret;
}

std::vector<unsigned char> generate_random_key(int size) {
    std::vector<unsigned char> key(size);
    RAND_bytes(key.data(), size);
    return key;
}

std::string aes_encrypt(const std::vector<unsigned char> &key, const std::vector<unsigned char> &data) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int outlen, tmplen;
    std::vector<unsigned char> outbuf(data.size() + AES_BLOCK_SIZE);
    std::vector<unsigned char> iv(AES_BLOCK_SIZE);
    RAND_bytes(iv.data(), AES_BLOCK_SIZE);
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key.data(), iv.data());
    EVP_EncryptUpdate(ctx, outbuf.data(), &outlen, data.data(), data.size());
    EVP_EncryptFinal_ex(ctx, outbuf.data() + outlen, &tmplen);
    outbuf.resize(outlen + tmplen);
    EVP_CIPHER_CTX_free(ctx);

    std::string iv_str(iv.begin(), iv.end());
    std::string encrypted_str(outbuf.begin(), outbuf.end());

    return base64_encode(iv_str) + base64_encode(encrypted_str);
}

int main() {
    std::vector<unsigned char> key = generate_random_key(32);
    std::vector<unsigned char> data = generate_random_key(16);
    std::string result = aes_encrypt(key, data);
    std::cout << result << std::endl;
    return 0;
}