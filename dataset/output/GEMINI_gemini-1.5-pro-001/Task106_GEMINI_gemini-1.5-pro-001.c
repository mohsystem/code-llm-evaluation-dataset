//This program needs to be linked with the OpenSSL library.
#include <stdio.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

int main() {
    // Generate RSA key pair
    RSA *rsa = RSA_new();
    BIGNUM *bne = BN_new();
    BN_set_word(bne, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, bne, NULL);
    BN_free(bne);

    // Encrypt a message
    const char *message = "This is a secret message";
    int message_length = strlen(message);
    int encrypted_length = RSA_size(rsa);
    unsigned char encrypted[encrypted_length];
    int length = RSA_public_encrypt(message_length, (const unsigned char *)message, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (length == -1) {
        fprintf(stderr, "Error encrypting message: %s\n", ERR_error_string(ERR_get_error(), NULL));
        RSA_free(rsa);
        return 1;
    }

    // Decrypt the message
    unsigned char decrypted[encrypted_length];
    length = RSA_private_decrypt(length, encrypted, decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (length == -1) {
        fprintf(stderr, "Error decrypting message: %s\n", ERR_error_string(ERR_get_error(), NULL));
        RSA_free(rsa);
        return 1;
    }
    decrypted[length] = '\0';

    // Print the results
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");
    printf("Decrypted Message: %s\n", decrypted);

    RSA_free(rsa);
    return 0;
}