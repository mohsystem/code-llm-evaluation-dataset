
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <openssl/aes.h>
#include <openssl/rand.h>

using namespace std;

const int KEY_SIZE = 32; // 256 bits
const int IV_SIZE = AES_BLOCK_SIZE;

vector<unsigned char> generateKey() {
    vector<unsigned char> key(KEY_SIZE);
    RAND_bytes(key.data(), KEY_SIZE);
    return key;
}

void encryptFile(const string& inputFile, const string& outputFile, const vector<unsigned char>& key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    vector<unsigned char> iv(IV_SIZE);
    RAND_bytes(iv.data(), IV_SIZE);
    outFile.write(reinterpret_cast<char*>(iv.data()), IV_SIZE);

    AES_KEY aesKey;
    AES_set_encrypt_key(key.data(), KEY_SIZE * 8, &aesKey);

    vector<unsigned char> inBuffer(AES_BLOCK_SIZE);
    vector<unsigned char> outBuffer(AES_BLOCK_SIZE);
    unsigned char ivec[AES_BLOCK_SIZE];
    memcpy(ivec, iv.data(), AES_BLOCK_SIZE);

    while (inFile.read(reinterpret_cast<char*>(inBuffer.data()), AES_BLOCK_SIZE)) {
        AES_cbc_encrypt(inBuffer.data(), outBuffer.data(), AES_BLOCK_SIZE, &aesKey, ivec, AES_ENCRYPT);
        outFile.write(reinterpret_cast<char*>(outBuffer.data()), AES_BLOCK_SIZE);
    }

    int lastBlockSize = inFile.gcount();
    if (lastBlockSize > 0) {
        memset(inBuffer.data() + lastBlockSize, AES_BLOCK_SIZE - lastBlockSize, AES_BLOCK_SIZE - lastBlockSize);
        AES_cbc_encrypt(inBuffer.data(), outBuffer.data(), AES_BLOCK_SIZE, &aesKey, ivec, AES_ENCRYPT);
        outFile.write(reinterpret_cast<char*>(outBuffer.data()), AES_BLOCK_SIZE);
    }

    inFile.close();
    outFile.close();
}

void decryptFile(const string& inputFile, const string& outputFile, const vector<unsigned char>& key) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    vector<unsigned char> iv(IV_SIZE);
    inFile.read(reinterpret_cast<char*>(iv.data()), IV_SIZE);

    AES_KEY aesKey;
    AES_set_decrypt_key(key.data(), KEY_SIZE * 8, &aesKey);

    vector<unsigned char> inBuffer(AES_BLOCK_SIZE);
    vector<unsigned char> outBuffer(AES_BLOCK_SIZE);
    unsigned char ivec[AES_BLOCK_SIZE];
    memcpy(ivec, iv.data(), AES_BLOCK_SIZE);

    while (inFile.read(reinterpret_cast<char*>(inBuffer.data()), AES_BLOCK_SIZE)) {
        AES_cbc_encrypt(inBuffer.data(), outBuffer.data(), AES_BLOCK_SIZE, &aesKey, ivec, AES_DECRYPT);
        outFile.write(reinterpret_cast<char*>(outBuffer.data()), AES_BLOCK_SIZE);
    }

    inFile.close();
    outFile.close();
}

int main() {
    vector<unsigned char> key = generateKey();
    cout << "Generated key: ";
    for (unsigned char c : key) {
        printf("%02x", c);
    }
    cout << endl;

    string inputFile;
    cout << "Enter the file path to encrypt: ";
    cin >> inputFile;

    string encryptedFile = inputFile + ".encrypted";
    encryptFile(inputFile, encryptedFile, key);
    cout << "File encrypted: " << encryptedFile << endl;

    char decryptChoice;
    cout << "Do you want to decrypt the file? (y/n): ";
    cin >> decryptChoice;

    if (tolower(decryptChoice) == 'y') {
        string decryptedFile = inputFile + ".decrypted";
        decryptFile(encryptedFile, decryptedFile, key);
        cout << "File decrypted: " << decryptedFile << endl;
    }

    return 0;
}
