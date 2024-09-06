
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <openssl/evp.h>
#include <openssl/rand.h>

std::vector<unsigned char> hash_password(const std::string& password) {
    const int salt_size = 16;
    const int key_size = 32;
    const int iterations = 100000;

    std::vector<unsigned char> salt(salt_size);
    RAND_bytes(salt.data(), salt_size);

    std::vector<unsigned char> key(key_size);
    PKCS5_PBKDF2_HMAC(password.c_str(), password.length(), salt.data(), salt_size,
                      iterations, EVP_sha256(), key_size, key.data());

    std::vector<unsigned char> result;
    result.insert(result.end(), salt.begin(), salt.end());
    result.insert(result.end(), key.begin(), key.end());

    return result;
}

void signup() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::vector<unsigned char> hashed_password = hash_password(password);

    std::ofstream file("passwords.txt", std::ios::app | std::ios::binary);
    file << username << ":";
    file.write(reinterpret_cast<const char*>(hashed_password.data()), hashed_password.size());
    file << std::endl;
    file.close();

    std::cout << "Signup successful!" << std::endl;
}

int main() {
    OpenSSL_add_all_algorithms();
    signup();
    EVP_cleanup();
    return 0;
}
