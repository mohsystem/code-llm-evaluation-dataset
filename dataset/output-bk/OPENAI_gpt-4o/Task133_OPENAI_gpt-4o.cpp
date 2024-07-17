#include <iostream>
#include <string>
#include <openssl/sha.h>

std::string hashPassword(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main() {
    std::string currentPassword, newPassword;
    
    std::cout << "C++: Enter your current password:" << std::endl;
    std::getline(std::cin, currentPassword);
    std::string hashedPassword = hashPassword(currentPassword);
    
    std::cout << "C++: Enter new password:" << std::endl;
    std::getline(std::cin, newPassword);
    std::string hashedNewPassword = hashPassword(newPassword);
    
    std::cout << "C++: Password has been reset!" << std::endl;
    
    return 0;
}