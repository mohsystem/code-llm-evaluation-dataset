#include <iostream>
#include <string>
#include <openssl/sha.h>

using namespace std;

string hash_password(const string& password, const string& salt) {
  string salted_password = salt + password;

  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, salted_password.c_str(), salted_password.size());
  SHA256_Final(hash, &sha256);

  string hashed_password;
  hashed_password.reserve(SHA256_DIGEST_LENGTH * 2);
  for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
    hashed_password += string(2, '0');
    sprintf(&hashed_password[i * 2], "%02x", hash[i]);
  }

  return hashed_password;
}