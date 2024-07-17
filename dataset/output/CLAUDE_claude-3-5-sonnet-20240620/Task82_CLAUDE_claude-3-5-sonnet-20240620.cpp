
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string hash_password(const std::string& password, const std::string& salt) {
    std::string combined = password + salt;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, combined.c_str(), combined.length());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill(\'0\') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main() {
    std::string password = "myPassword123";
    std::string salt = "randomSalt";
    std::string hashed_password = hash_password(password, salt);
    std::cout << "Hashed password: " << hashed_password << std::endl;
    return 0;
}
