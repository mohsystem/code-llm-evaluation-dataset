#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/rand.h>

std::string hash_password(const std::string& password, const std::string& salt = "") {
  // Generate a random salt if none is provided
  std::string salt_to_use = salt;
  if (salt_to_use.empty()) {
    unsigned char salt_bytes[16];
    RAND_bytes(salt_bytes, sizeof(salt_bytes));
    salt_to_use = std::string((char*)salt_bytes, sizeof(salt_bytes));
  }

  // Concatenate the password and salt
  std::string password_salt = password + salt_to_use;

  // Calculate the SHA-256 hash
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, password_salt.c_str(), password_salt.size());
  SHA256_Final(hash, &sha256);

  // Convert the hash to a hexadecimal string
  std::stringstream ss;
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }

  // Return the hashed password and salt
  return ss.str() + ":" + salt_to_use;
}

int main() {
  std::string password = "mysecretpassword";
  std::string hashed_password = hash_password(password);
  std::cout << "Hashed password: " << hashed_password << std::endl;
  return 0;
}