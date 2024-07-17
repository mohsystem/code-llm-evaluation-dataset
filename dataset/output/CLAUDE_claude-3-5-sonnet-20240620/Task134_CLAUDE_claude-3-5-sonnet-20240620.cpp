
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <openssl/aes.h>
#include <openssl/rand.h>

const std::string KEY_FILE = "secret.key";
const int KEY_SIZE = 32; // 256 bits

std::vector<unsigned char> generate_key() {
    std::vector<unsigned char> key(KEY_SIZE);
    RAND_bytes(key.data(), KEY_SIZE);
    return key;
}

void save_key(const std::vector<unsigned char>& key, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<const char*>(key.data()), key.size());
}

std::vector<unsigned char> load_key(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    std::vector<unsigned char> key(KEY_SIZE);
    file.read(reinterpret_cast<char*>(key.data()), KEY_SIZE);
    return key;
}

std::vector<unsigned char> encrypt_message(const std::string& message, const std::vector<unsigned char>& key) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key.data(), KEY_SIZE * 8, &aes_key);

    std::vector<unsigned char> encrypted((message.size() + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE * AES_BLOCK_SIZE);
    for (size_t i = 0; i < message.size(); i += AES_BLOCK_SIZE) {
        AES_encrypt(reinterpret_cast<const unsigned char*>(message.data() + i),
                    encrypted.data() + i,
                    &aes_key);
    }

    return encrypted;
}

std::string decrypt_message(const std::vector<unsigned char>& encrypted, const std::vector<unsigned char>& key) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key.data(), KEY_SIZE * 8, &aes_key);

    std::vector<unsigned char> decrypted(encrypted.size());
    for (size_t i = 0; i < encrypted.size(); i += AES_BLOCK_SIZE) {
        AES_decrypt(encrypted.data() + i,
                    decrypted.data() + i,
                    &aes_key);
    }

    return std::string(decrypted.begin(), decrypted.end());
}

int main() {
    std::vector<unsigned char> key;

    if (std::ifstream(KEY_FILE).good()) {
        key = load_key(KEY_FILE);
    } else {
        key = generate_key();
        save_key(key, KEY_FILE);
    }

    std::string message = "Hello, this is a secret message!";
    std::vector<unsigned char> encrypted = encrypt_message(message, key);
    std::string decrypted = decrypt_message(encrypted, key);

    std::cout << "Original: " << message << std::endl;
    std::cout << "Encrypted: ";
    for (unsigned char c : encrypted) {
        std::cout << std::hex << static_cast<int>(c);
    }
    std::cout << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
