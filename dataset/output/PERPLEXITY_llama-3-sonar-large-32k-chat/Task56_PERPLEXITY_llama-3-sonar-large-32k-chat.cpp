#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string generateToken(const std::string& username, const std::string& password) {
    std::string timestamp = std::to_string(time(nullptr));
    std::string tokenStr = username + password + timestamp;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)tokenStr.c_str(), tokenStr.size(), hash);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    std::string username = "john";
    std::string password = "password123";
    std::cout << "Token: " << generateToken(username, password) << std::endl;
    return 0;
}