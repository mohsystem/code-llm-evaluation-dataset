code here:
#include <iostream>
#include <string>
#include <unordered_map>
#include <openssl/sha.h>

class KeyManager {
private:
    std::unordered_map<std::string, std::string> keys;

public:
    std::string generateKey(const std::string& username) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, username.c_str(), username.size());
        SHA256_Final(hash, &sha256);
        std::string key;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            char buffer[3];
            sprintf(buffer, "%02x", hash[i]);
            key += buffer;
        }
        this->keys[username] = key;
        return key;
    }

    std::string getKey(const std::string& username) {
        return this->keys[username];
    }

    void deleteKey(const std::string& username) {
        this->keys.erase(username);
    }
};

int main() {
    KeyManager manager;
    std::cout << manager.generateKey("user1") << std::endl;
    std::cout << manager.getKey("user1") << std::endl;
    manager.deleteKey("user1");
    std::cout << manager.getKey("user1") << std::endl;
    return 0;
}