// C++
#include <iostream>
#include <openssl/aes.h>
#include <string.h>

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext)
{
  AES_KEY enc_key;
  AES_set_encrypt_key(key, 128, &enc_key);
  AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
}

int main() {
  unsigned char key[] = "This is a secret key";
  unsigned char iv[] = "RandomInitVector";
  unsigned char plaintext[] = "This is the plaintext to be encrypted";
  unsigned char ciphertext[128];

  encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

  std::cout << "Encrypted key: ";
  for(int i = 0; i < strlen((char *)plaintext); i++) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)ciphertext[i];
  }
  std::cout << std::endl;

  return 0;
}