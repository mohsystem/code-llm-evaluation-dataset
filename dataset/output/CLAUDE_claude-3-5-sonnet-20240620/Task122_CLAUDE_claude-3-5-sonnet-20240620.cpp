
#include <iostream>
#include <string>
#include <map>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::map<std::string, std::string> passwords;

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill(\'0\') << (int)hash[i];
    }
    return ss.str();
}

void signup() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::string hashed_password = sha256(password);
    passwords[username] = hashed_password;
    std::cout << "Signup successful!" << std::endl;
}

int main() {
    char choice;
    do {
        signup();
        std::cout << "Do you want to add another user? (y/n): ";
        std::cin >> choice;
    } while (choice == \'y\' || choice == \'Y\');

    std::cout << "Final password dictionary:" << std::endl;
    for (const auto& pair : passwords) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
