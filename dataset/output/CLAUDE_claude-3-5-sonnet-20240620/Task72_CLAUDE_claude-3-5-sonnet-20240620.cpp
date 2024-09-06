
#include <iostream>
#include <string>
#include <vector>
#include <openssl/aes.h>
#include <openssl/rand.h>

std::vector<unsigned char> encrypt_data(const std::string& data, const std::vector<unsigned char>& key) {
    // Create a static initialization vector (IV)
    std::vector<unsigned char> iv(AES_BLOCK_SIZE, 0);

    // Initialize a cipher using AES in CBC mode with the static IV
    AES_KEY aes_key;
    AES_set_encrypt_key(key.data(), key.size() * 8, &aes_key);

    // Pad the input data to match the block size required by the cipher
    size_t padded_size = ((data.size() + AES_BLOCK_SIZE - 1) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    std::vector<unsigned char> padded_data(padded_size, 0);
    std::copy(data.begin(), data.end(), padded_data.begin());

    // Encrypt the padded data using the cipher
    std::vector<unsigned char> encrypted_data(padded_size);
    AES_cbc_encrypt(padded_data.data(), encrypted_data.data(), padded_size, &aes_key, iv.data(), AES_ENCRYPT);

    return encrypted_data;
}

int main() {
    std::vector<unsigned char> key(32);
    RAND_bytes(key.data(), key.size());

    std::string data = "This is a secret message.";
    std::vector<unsigned char> encrypted = encrypt_data(data, key);

    for (unsigned char c : encrypted) {
        std::cout << std::hex << (int)c << " ";
    }
    std::cout << std::endl;

    return 0;
}
