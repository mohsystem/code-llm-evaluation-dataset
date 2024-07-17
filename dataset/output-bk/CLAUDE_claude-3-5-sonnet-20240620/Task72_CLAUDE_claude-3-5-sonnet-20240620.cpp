
#include <iostream>
#include <string>
#include <vector>
#include <openssl/aes.h>
#include <openssl/rand.h>

class AESEncryption {
private:
    static const int AES_BLOCK_SIZE = 16;
    std::vector<unsigned char> iv;

    void pad_data(std::vector<unsigned char>& data) {
        int padding = AES_BLOCK_SIZE - (data.size() % AES_BLOCK_SIZE);
        data.insert(data.end(), padding, padding);
    }

public:
    AESEncryption() {
        iv.resize(AES_BLOCK_SIZE);
        RAND_bytes(iv.data(), AES_BLOCK_SIZE);
    }

    std::vector<unsigned char> encrypt(const std::string& data, const std::string& key) {
        std::vector<unsigned char> padded_data(data.begin(), data.end());
        pad_data(padded_data);

        std::vector<unsigned char> encrypted_data(padded_data.size());
        AES_KEY aes_key;
        AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aes_key);
        AES_cbc_encrypt(padded_data.data(), encrypted_data.data(), padded_data.size(), &aes_key, iv.data(), AES_ENCRYPT);

        return encrypted_data;
    }
};

int main() {
    AESEncryption aes;
    std::string data = "Hello, World!";
    std::string key = "1234567890123456";

    std::vector<unsigned char> encrypted = aes.encrypt(data, key);

    std::cout << "Encrypted: ";
    for (unsigned char c : encrypted) {
        printf("%02x", c);
    }
    std::cout << std::endl;

    return 0;
}
