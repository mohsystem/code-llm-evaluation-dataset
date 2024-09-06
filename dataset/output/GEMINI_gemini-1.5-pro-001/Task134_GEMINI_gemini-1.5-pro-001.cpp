#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

using namespace std;

// Function to handle OpenSSL errors
void handleErrors(const char* operation) {
    cerr << "ERROR: " << operation << " failed" << endl;
    ERR_print_errors_fp(stderr);
    exit(1);
}

// Function to generate a random cryptographic key
string generateKey(int keySize) {
    unsigned char key[keySize];
    if (RAND_bytes(key, keySize) != 1) {
        handleErrors("RAND_bytes");
    }

    // Convert the key to a hexadecimal string
    string keyString;
    for (int i = 0; i < keySize; ++i) {
        keyString += (key[i] < 0x10 ? "0" : "") + string(1, key[i]);
    }
    return keyString;
}

// Function to encrypt a message using AES-256-CBC
string encryptMessage(const string& message, const string& key) {
    // Create a cipher context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (ctx == nullptr) {
        handleErrors("EVP_CIPHER_CTX_new");
    }

    // Set up the cipher
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
                          reinterpret_cast<const unsigned char*>(key.c_str()), nullptr) != 1) {
        handleErrors("EVP_EncryptInit_ex");
    }

    // Encrypt the message
    int ciphertextLen = message.size() + EVP_CIPHER_block_size(EVP_aes_256_cbc());
    unsigned char ciphertext[ciphertextLen];
    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &len,
                          reinterpret_cast<const unsigned char*>(message.c_str()), message.size()) != 1) {
        handleErrors("EVP_EncryptUpdate");
    }
    int finalLen;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &finalLen) != 1) {
        handleErrors("EVP_EncryptFinal_ex");
    }
    ciphertextLen = len + finalLen;

    // Clean up the cipher context
    EVP_CIPHER_CTX_free(ctx);

    // Convert the ciphertext to a hexadecimal string
    string ciphertextString;
    for (int i = 0; i < ciphertextLen; ++i) {
        ciphertextString += (ciphertext[i] < 0x10 ? "0" : "") + string(1, ciphertext[i]);
    }
    return ciphertextString;
}

// Function to decrypt a message using AES-256-CBC
string decryptMessage(const string& ciphertext, const string& key) {
    // Create a cipher context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (ctx == nullptr) {
        handleErrors("EVP_CIPHER_CTX_new");
    }

    // Set up the cipher
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
                          reinterpret_cast<const unsigned char*>(key.c_str()), nullptr) != 1) {
        handleErrors("EVP_DecryptInit_ex");
    }

    // Decrypt the message
    int plaintextLen = ciphertext.size() / 2; // Hexadecimal string to binary
    unsigned char plaintext[plaintextLen];
    int len;
    if (EVP_DecryptUpdate(ctx, plaintext, &len,
                          reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size() / 2) != 1) {
        handleErrors("EVP_DecryptUpdate");
    }
    int finalLen;
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &finalLen) != 1) {
        handleErrors("EVP_DecryptFinal_ex");
    }
    plaintextLen = len + finalLen;

    // Clean up the cipher context
    EVP_CIPHER_CTX_free(ctx);

    // Convert the plaintext to a string
    string message(reinterpret_cast<char*>(plaintext), plaintextLen);
    return message;
}

int main() {
    // Initialize OpenSSL
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    while (true) {
        cout << "\nCryptographic Key Manager:" << endl;
        cout << "1. Generate a new key" << endl;
        cout << "2. Encrypt a message" << endl;
        cout << "3. Decrypt a message" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Generate a 32-byte (256-bit) key
                string key = generateKey(32);
                cout << "Generated Key: " << key << endl;
                break;
            }
            case 2: {
                cin.ignore(); // Consume newline character
                cout << "Enter the message to encrypt: ";
                string message;
                getline(cin, message);

                cout << "Enter the key: ";
                string key;
                getline(cin, key);

                string ciphertext = encryptMessage(message, key);
                cout << "Encrypted message: " << ciphertext << endl;
                break;
            }
            case 3: {
                cin.ignore(); // Consume newline character
                cout << "Enter the message to decrypt: ";
                string ciphertext;
                getline(cin, ciphertext);

                cout << "Enter the key: ";
                string key;
                getline(cin, key);

                string plaintext = decryptMessage(ciphertext, key);
                cout << "Decrypted message: " << plaintext << endl;
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}