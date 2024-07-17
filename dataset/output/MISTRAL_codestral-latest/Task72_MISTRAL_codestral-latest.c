// C
#include <openssl/aes.h>
#include <string.h>
#include <stdio.h>

#define KEY "1234567890123456" // 128 bit key
#define IV "RandomInitVector" // 16 bytes IV

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext)
{
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
}