#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string getHash(const std::string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::string hexString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char buf[3];
        snprintf(buf, sizeof(buf), "%02x", hash[i]);
        hexString.append(buf);
    }
    return hexString;
}

bool authenticate(const std::string &inputPassword, const std::string &storedPasswordHash) {
    return getHash(inputPassword) == storedPasswordHash;
}

int main() {
    std::string storedPasswordHash = getHash("securepassword");
    std::string inputPassword;
    std::cout << "Enter your password: ";
    std::getline(std::cin, inputPassword);
    
    if (authenticate(inputPassword, storedPasswordHash)) {
        std::cout << "Authentication successful." << std::endl;
    } else {
        std::cout << "Authentication failed." << std::endl;
    }
    
    return 0;
}