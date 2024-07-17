#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define KEY_LENGTH 2048

int main() {
    RSA *keypair = RSA_generate_key(KEY_LENGTH, RSA_F4, NULL, NULL);

    if (keypair == NULL) {
        fprintf(stderr, "Failed to generate RSA key pair.
");
        return 1;
    }

    // Write private key to file
    FILE *private_key_file = fopen("private.pem", "wb");
    if (private_key_file == NULL) {
        fprintf(stderr, "Failed to open private key file.
");
        return 1;
    }
    PEM_write_RSAPrivateKey(private_key_file, keypair, NULL, NULL, 0, NULL, NULL);
    fclose(private_key_file);

    // Write public key to file
    FILE *public_key_file = fopen("public.pem", "wb");
    if (public_key_file == NULL) {
        fprintf(stderr, "Failed to open public key file.
");
        return 1;
    }
    PEM_write_RSAPublicKey(public_key_file, keypair);
    fclose(public_key_file);

    // Encrypt message
    const char *message = "Hello, RSA!";
    int message_length = strlen(message);
    unsigned char ciphertext[RSA_size(keypair)];
    int ciphertext_length = RSA_public_encrypt(message_length, (const unsigned char *)message, ciphertext, keypair, RSA_PKCS1_PADDING);

    if (ciphertext_length == -1) {
        fprintf(stderr, "Encryption failed: %s
", ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    // Decrypt message
    unsigned char decrypted[RSA_size(keypair)];
    int decrypted_length = RSA_private_decrypt(ciphertext_length, ciphertext, decrypted, keypair, RSA_PKCS1_PADDING);

    if (decrypted_length == -1) {
        fprintf(stderr, "Decryption failed: %s
", ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_length; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("
");

    printf("Plaintext: %s
", decrypted);

    RSA_free(keypair);

    return 0;
}