#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string compute_hash(const std::string& password, const std::string& salt) {
    std::string combined = password + salt;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(combined.c_str()), combined.size(), hash);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main() {
    const std::string password = "example_password";
    const std::string salt = "random_salt";
    std::cout << "C++ Hash: " << compute_hash(password, salt) << std::endl;
    return 0;
}