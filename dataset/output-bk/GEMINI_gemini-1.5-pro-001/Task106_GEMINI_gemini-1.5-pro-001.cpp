#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define KEY_LENGTH 2048

int main() {
    // Generate RSA key pair
    RSA *keypair = RSA_generate_key(KEY_LENGTH, RSA_F4, nullptr, nullptr);
    if (keypair == nullptr) {
        std::cerr << "Failed to generate RSA key pair: " << ERR_error_string(ERR_get_error(), nullptr) << std::endl;
        return 1;
    }

    // Write private key to file
    FILE *private_key_file = fopen("private.pem", "wb");
    if (private_key_file == nullptr) {
        std::cerr << "Failed to open private key file." << std::endl;
        return 1;
    }
    PEM_write_RSAPrivateKey(private_key_file, keypair, nullptr, nullptr, 0, nullptr, nullptr);
    fclose(private_key_file);

    // Write public key to file
    FILE *public_key_file = fopen("public.pem", "wb");
    if (public_key_file == nullptr) {
        std::cerr << "Failed to open public key file." << std::endl;
        return 1;
    }
    PEM_write_RSAPublicKey(public_key_file, keypair);
    fclose(public_key_file);

    // Encrypt message
    const std::string message = "Hello, RSA!";
    int message_length = message.length();
    unsigned char ciphertext[RSA_size(keypair)];
    int ciphertext_length = RSA_public_encrypt(message_length, (const unsigned char *)message.c_str(), ciphertext, keypair, RSA_PKCS1_PADDING);

    if (ciphertext_length == -1) {
        std::cerr << "Encryption failed: " << ERR_error_string(ERR_get_error(), nullptr) << std::endl;
        return 1;
    }

    // Decrypt message
    unsigned char decrypted[RSA_size(keypair)];
    int decrypted_length = RSA_private_decrypt(ciphertext_length, ciphertext, decrypted, keypair, RSA_PKCS1_PADDING);

    if (decrypted_length == -1) {
        std::cerr << "Decryption failed: " << ERR_error_string(ERR_get_error(), nullptr) << std::endl;
        return 1;
    }

    std::cout << "Ciphertext: ";
    for (int i = 0; i < ciphertext_length; i++) {
        std::cout << std::hex << (int)ciphertext[i];
    }
    std::cout << std::endl;

    std::cout << "Plaintext: " << decrypted << std::endl;

    RSA_free(keypair);

    return 0;
}