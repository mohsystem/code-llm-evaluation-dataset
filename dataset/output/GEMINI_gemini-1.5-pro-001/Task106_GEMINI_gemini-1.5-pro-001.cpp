#include <iostream>
#include <string>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

using namespace std;

// Function to generate RSA key pair
void generateKeys(RSA* &rsa) {
  BIGNUM *bne = BN_new();
  BN_set_word(bne, RSA_F4);

  rsa = RSA_new();
  RSA_generate_key_ex(rsa, 2048, bne, NULL);
  BN_free(bne);
}

// Function to encrypt a message
string encrypt(const string &message, RSA *rsa) {
  int encryptedLength = RSA_size(rsa);
  unsigned char *encrypted = new unsigned char[encryptedLength];
  int length = RSA_public_encrypt(message.length(), (const unsigned char*)message.c_str(), encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
  if (length == -1) {
    cerr << "Error encrypting message: " << ERR_error_string(ERR_get_error(), NULL) << endl;
    delete[] encrypted;
    return "";
  }
  string encryptedMessage((char*)encrypted, length);
  delete[] encrypted;
  return encryptedMessage;
}

// Function to decrypt a message
string decrypt(const string &encryptedMessage, RSA *rsa) {
  int decryptedLength = RSA_size(rsa);
  unsigned char *decrypted = new unsigned char[decryptedLength];
  int length = RSA_private_decrypt(encryptedMessage.length(), (const unsigned char*)encryptedMessage.c_str(), decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
  if (length == -1) {
    cerr << "Error decrypting message: " << ERR_error_string(ERR_get_error(), NULL) << endl;
    delete[] decrypted;
    return "";
  }
  string decryptedMessage((char*)decrypted, length);
  delete[] decrypted;
  return decryptedMessage;
}

int main() {
  // Generate RSA key pair
  RSA *rsa = NULL;
  generateKeys(rsa);

  // Encrypt a message
  string message = "This is a secret message";
  string encryptedMessage = encrypt(message, rsa);

  // Decrypt the message
  string decryptedMessage = decrypt(encryptedMessage, rsa);

  // Print the results
  cout << "Original Message: " << message << endl;
  cout << "Encrypted Message: " << encryptedMessage << endl;
  cout << "Decrypted Message: " << decryptedMessage << endl;

  RSA_free(rsa);
  return 0;
}