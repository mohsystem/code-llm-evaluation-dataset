// C++
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <iostream>

int main() {
    // Generate RSA key pair
    RSA* rsa = RSA_new();
    BIGNUM* e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, e, nullptr);

    // Export private key in OpenSSH format
    BIO* bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(bio, rsa, nullptr, nullptr, 0, nullptr, nullptr);

    // Print the private key
    char* private_key;
    long private_key_length = BIO_get_mem_data(bio, &private_key);
    std::cout.write(private_key, private_key_length);

    // Free resources
    BIO_free(bio);
    RSA_free(rsa);
    BN_free(e);

    return 0;
}