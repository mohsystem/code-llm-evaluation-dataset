#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/rand.h>

std::string hashPassword(const std::string& password, const std::string& salt) {
    const int iterations = 100000;
    const int keyLength = 32;
    unsigned char hash[keyLength];

    PKCS5_PBKDF2_HMAC(password.c_str(), password.length(),
                      reinterpret_cast<const unsigned char*>(salt.c_str()), salt.length(),
                      iterations, EVP_sha256(), keyLength, hash);

    std::string hashedPassword(reinterpret_cast<char*>(hash), keyLength);
    return hashedPassword;
}

int main() {
    std::string password = "my_password";
    std::string salt = "salt_";
    std::string hashedPassword = hashPassword(password, salt);
    std::cout << hashedPassword << std::endl;
    return 0;
}