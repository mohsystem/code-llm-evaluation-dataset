
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

std::string hashPassword(const std::string& password, const std::string& salt) {
    return sha256(password + salt);
}

int main() {
    std::string password = "mypassword123";
    std::string salt = "randomsalt";
    std::string hashedPassword = hashPassword(password, salt);
    std::cout << "Hashed password: " << hashedPassword << std::endl;
    return 0;
}
