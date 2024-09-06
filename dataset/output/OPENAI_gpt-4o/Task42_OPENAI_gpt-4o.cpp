#include <iostream>
#include <unordered_map>
#include <string>
#include <openssl/sha.h>

class UserAuth {
private:
    std::unordered_map<std::string, std::string> users;

    std::string hashPassword(const std::string &password) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, password.c_str(), password.size());
        SHA256_Final(hash, &sha256);
        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }

public:
    void addUser(const std::string &username, const std::string &password) {
        users[username] = hashPassword(password);
    }

    bool authenticate(const std::string &username, const std::string &password) {
        return users[username] == hashPassword(password);
    }
};

int main() {
    UserAuth auth;
    auth.addUser("user", "pass");
    std::cout << auth.authenticate("user", "pass") << std::endl;
    std::cout << auth.authenticate("user", "wrongpass") << std::endl;
    return 0;
}