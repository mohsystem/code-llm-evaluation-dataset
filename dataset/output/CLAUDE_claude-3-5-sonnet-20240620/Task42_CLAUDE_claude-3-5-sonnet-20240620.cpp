
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <openssl/sha.h>
#include <openssl/rand.h>

std::unordered_map<std::string, std::vector<unsigned char>> users;

std::vector<unsigned char> hash_password(const std::string& password, const std::vector<unsigned char>& salt) {
    std::vector<unsigned char> result(salt.size() + SHA256_DIGEST_LENGTH);
    std::copy(salt.begin(), salt.end(), result.begin());

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, salt.data(), salt.size());
    SHA256_Update(&sha256, password.c_str(), password.length());
    SHA256_Final(result.data() + salt.size(), &sha256);

    return result;
}

bool verify_password(const std::vector<unsigned char>& stored_password, const std::string& provided_password) {
    std::vector<unsigned char> salt(stored_password.begin(), stored_password.begin() + 32);
    std::vector<unsigned char> hashed = hash_password(provided_password, salt);
    return hashed == stored_password;
}

bool register_user(const std::string& username, const std::string& password) {
    if (users.find(username) != users.end()) {
        return false;
    }
    std::vector<unsigned char> salt(32);
    RAND_bytes(salt.data(), salt.size());
    users[username] = hash_password(password, salt);
    return true;
}

bool login(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it == users.end()) {
        return false;
    }
    return verify_password(it->second, password);
}

int main() {
    register_user("alice", "password123");
    std::cout << login("alice", "password123") << std::endl; // 1 (true)
    std::cout << login("alice", "wrongpassword") << std::endl; // 0 (false)
    return 0;
}
