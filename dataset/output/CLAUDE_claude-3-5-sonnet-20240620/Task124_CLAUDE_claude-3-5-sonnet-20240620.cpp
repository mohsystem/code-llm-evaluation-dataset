
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string encrypt(const std::string& data) {
    std::string result = data;
    for (char& c : result) {
        c = c + 1;
    }
    return result;
}

std::string decrypt(const std::string& encodedData) {
    std::string result = encodedData;
    for (char& c : result) {
        c = c - 1;
    }
    return result;
}

int main() {
    std::map<std::string, std::string> sensitiveData = {
        {"credit_card", "1234-5678-9012-3456"},
        {"ssn", "123-45-6789"},
        {"password", "mySecretPass123"}
    };

    std::map<std::string, std::string> encryptedData;
    for (const auto& pair : sensitiveData) {
        encryptedData[pair.first] = encrypt(pair.second);
    }

    std::cout << "Encrypted data:" << std::endl;
    for (const auto& pair : encryptedData) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::map<std::string, std::string> decryptedData;
    for (const auto& pair : encryptedData) {
        decryptedData[pair.first] = decrypt(pair.second);
    }

    std::cout << "\\nDecrypted data:" << std::endl;
    for (const auto& pair : decryptedData) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
