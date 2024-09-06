//  Compile with:
//  gcc -o crypto_manager crypto_manager.c -lcrypto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define ENCRYPT 1
#define DECRYPT 0

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt_decrypt(unsigned char *input, int input_len, unsigned char *key, unsigned char *iv, unsigned char *output, int enc)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int output_len;

    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL)
        handleErrors();
    if (enc == ENCRYPT)
    {
        if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
            handleErrors();
    }
    else
    {
        if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
            handleErrors();
    }

    if (EVP_CipherUpdate(ctx, output, &len, input, input_len) != 1)
        handleErrors();
    output_len = len;
    if (EVP_CipherFinal_ex(ctx, output + len, &len) != 1)
        handleErrors();
    output_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return output_len;
}

int main()
{
    unsigned char key[32];
    unsigned char iv[16];
    const int KEY_SIZE = sizeof(key);
    const int IV_SIZE = sizeof(iv);

    // Generate Random Key and IV
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    // Print Key and IV in Hex format
    printf("Generated Key: ");
    for (int i = 0; i < KEY_SIZE; i++)
        printf("%02x", key[i]);
    printf("\n");

    printf("Generated IV: ");
    for (int i = 0; i < IV_SIZE; i++)
        printf("%02x", iv[i]);
    printf("\n");

    char *plaintext = (char *)"This is a secret message.";
    int plaintext_len = strlen(plaintext);
    unsigned char ciphertext[128];
    int ciphertext_len;
    unsigned char decryptedtext[128];
    int decryptedtext_len;

    ciphertext_len = encrypt_decrypt((unsigned char *)plaintext, plaintext_len, key, iv, ciphertext, ENCRYPT);
    printf("Ciphertext is:\n");
    BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

    decryptedtext_len = encrypt_decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, DECRYPT);
    decryptedtext[decryptedtext_len] = '\0';
    printf("Decrypted text is: %s\n", decryptedtext);

    return 0;
}