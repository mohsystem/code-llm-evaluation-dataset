// C++ code for RSA encryption and decryption is quite lengthy and requires external libraries.
// This example uses OpenSSL library for RSA implementation.
// Please make sure to include the OpenSSL library in your project.

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Generate a new RSA key pair
    RSA* rsa = RSA_new();
    BIGNUM* e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, e, nullptr);

    // Export the public key
    BIO* bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSA_PUBKEY(bio, rsa);
    char* publicKey;
    size_t publicKeyLength;
    BIO_get_mem_data(bio, &publicKey);
    BIO_get_mem_data(bio, &publicKeyLength);

    // Data to be encrypted
    std::string data = "Hello, World!";

    // Encrypt the data
    std::vector<unsigned char> encryptedData(RSA_size(rsa));
    RSA_public_encrypt(data.size(), reinterpret_cast<const unsigned char*>(data.c_str()), encryptedData.data(), rsa, RSA_PKCS1_PADDING);

    // Decrypt the data
    std::vector<unsigned char> decryptedData(RSA_size(rsa));
    RSA_private_decrypt(RSA_size(rsa), encryptedData.data(), decryptedData.data(), rsa, RSA_PKCS1_PADDING);

    std::cout << "Encrypted data: ";
    for (const auto& byte : encryptedData) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    std::cout << std::endl;

    std::cout << "Decrypted data: " << std::string(decryptedData.begin(), decryptedData.end()) << std::endl;

    // Clean up
    RSA_free(rsa);
    BN_free(e);
    BIO_free(bio);

    return 0;
}