#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

void saveKey(const std::vector<unsigned char>& key, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<const char*>(key.data()), key.size());
    file.close();
}

std::vector<unsigned char> loadKey(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    std::vector<unsigned char> key((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return key;
}

void encryptFile(const std::vector<unsigned char>& key, const std::string& infile, const std::string& outfile) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key.data(), 128, &aes_key);

    std::ifstream ifs(infile, std::ios::binary);
    std::ofstream ofs(outfile, std::ios::binary);

    std::vector<unsigned char> buffer(AES_BLOCK_SIZE);
    while (ifs.read(reinterpret_cast<char*>(buffer.data()), AES_BLOCK_SIZE)) {
        std::vector<unsigned char> ciphertext(AES_BLOCK_SIZE);
        AES_encrypt(buffer.data(), ciphertext.data(), &aes_key);
        ofs.write(reinterpret_cast<char*>(ciphertext.data()), AES_BLOCK_SIZE);
    }

    ifs.close();
    ofs.close();
}

void decryptFile(const std::vector<unsigned char>& key, const std::string& infile, const std::string& outfile) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key.data(), 128, &aes_key);

    std::ifstream ifs(infile, std::ios::binary);
    std::ofstream ofs(outfile, std::ios::binary);

    std::vector<unsigned char> buffer(AES_BLOCK_SIZE);
    while (ifs.read(reinterpret_cast<char*>(buffer.data()), AES_BLOCK_SIZE)) {
        std::vector<unsigned char> plaintext(AES_BLOCK_SIZE);
        AES_decrypt(buffer.data(), plaintext.data(), &aes_key);
        ofs.write(reinterpret_cast<char*>(plaintext.data()), AES_BLOCK_SIZE);
    }

    ifs.close();
    ofs.close();
}

int main() {
    std::string keyfile = "filekey.key";
    std::string infile = "test.txt";
    std::string encryptedFile = "test.encrypted";
    std::string decryptedFile = "test.decrypted";

    std::vector<unsigned char> key(16);
    RAND_bytes(key.data(), 16);
    saveKey(key, keyfile);

    encryptFile(key, infile, encryptedFile);

    std::vector<unsigned char> loadedKey = loadKey(keyfile);
    decryptFile(loadedKey, encryptedFile, decryptedFile);

    return 0;
}