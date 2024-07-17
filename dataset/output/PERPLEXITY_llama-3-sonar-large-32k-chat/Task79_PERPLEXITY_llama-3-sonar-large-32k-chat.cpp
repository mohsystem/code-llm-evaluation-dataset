#include <iostream>
#include <string>

std::string createCipher(std::string secretKey) {
    return secretKey + secretKey + secretKey + secretKey + secretKey + secretKey + secretKey + secretKey + secretKey + secretKey;
}

std::string encryptMessage(std::string message, std::string cipher) {
    std::string encryptedMessage;
    for (int i = 0; i < message.length(); i++) {
        encryptedMessage += (char) (message[i] + cipher[i % cipher.length()]);
    }
    return encryptedMessage;
}

int main() {
    std::string message = "Hello, World!";
    std::string secretKey = "mySecretKey";
    std::string cipher = createCipher(secretKey);
    std::string encryptedMessage = encryptMessage(message, cipher);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;
    return 0;
}