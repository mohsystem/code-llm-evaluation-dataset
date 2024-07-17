#include <iostream>
#include <iomanip>
#include <string>
#include <openssl/sha.h>

void hashPassword(const std::string& password, std::string& hashedPassword) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    std::ostringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    hashedPassword = ss.str();
}

void updatePasswordInDatabase(const std::string& username, const std::string& hashedPassword) {
    std::cout << "Updating password for user: " << username << std::endl;
    // Database interaction code would go here
}

int main() {
    std::string username, password, hashedPassword;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter new password: ";
    std::cin >> password;

    hashPassword(password, hashedPassword);
    updatePasswordInDatabase(username, hashedPassword);

    return 0;
}