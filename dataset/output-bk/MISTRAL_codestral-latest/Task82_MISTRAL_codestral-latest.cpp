// C++
#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/rand.h>

#define SALT_SIZE 16
#define ITERATIONS 10000

std::string hash_password(const std::string &password, const unsigned char *salt) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    std::string hashed_password;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, salt, SALT_SIZE);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    for (int i = 0; i < ITERATIONS; i++) {
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, hash, SHA256_DIGEST_LENGTH);
        SHA256_Final(hash, &sha256);
    }

    char buf[3];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        snprintf(buf, sizeof(buf), "%02x", hash[i]);
        hashed_password += buf;
    }

    return hashed_password;
}

int main() {
    std::string password = "your_password";
    unsigned char salt[SALT_SIZE];

    RAND_bytes(salt, SALT_SIZE);
    std::string hashed_password = hash_password(password, salt);

    std::cout << hashed_password << std::endl;

    return 0;
}