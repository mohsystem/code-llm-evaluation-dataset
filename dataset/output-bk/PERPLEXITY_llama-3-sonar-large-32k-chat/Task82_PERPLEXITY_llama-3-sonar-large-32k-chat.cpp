#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/err.h>
#include <base64.h>

int main() {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    std::string password = "mypassword";
    std::string salt = "mysalt";
    std::string combined = password + salt;
    SHA256((unsigned char*)combined.c_str(), combined.length(), hash);
    char base64[BASE64_ENCODE_LENGTH(SHA256_DIGEST_LENGTH) + 1];
    base64_encode(hash, SHA256_DIGEST_LENGTH, base64);
    std::cout << "Hash: " << base64 << std::endl;
    return 0;
}