#include <iostream>
#include <fstream>
#include <string>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

using namespace std;

const int KEY_SIZE = 256; // 256 bits = 32 bytes
const int IV_SIZE = 128;  // 128 bits = 16 bytes
const string KEY_FILE = "secret.key";
const string IV_FILE = "iv.data";

// Function to generate a random key and IV
void generateKeyAndIV() {
    unsigned char key[KEY_SIZE / 8];
    unsigned char iv[IV_SIZE / 8];

    // Generate random key and IV
    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        cerr << "Error generating key/IV: " << ERR_error_string(ERR_get_error(), NULL) << endl;
        return;
    }

    // Write key and IV to files
    ofstream keyFile(KEY_FILE, ios::binary);
    ofstream ivFile(IV_FILE, ios::binary);
    if (!keyFile.is_open() || !ivFile.is_open()) {
        cerr << "Error opening key/IV file" << endl;
        return;
    }
    keyFile.write((char*)key, sizeof(key));
    ivFile.write((char*)iv, sizeof(iv));
    keyFile.close();
    ivFile.close();
    cout << "Key and IV generated and saved to files." << endl;
}

// Function to load key and IV from files
bool loadKeyAndIV(unsigned char* key, unsigned char* iv) {
    ifstream keyFile(KEY_FILE, ios::binary);
    ifstream ivFile(IV_FILE, ios::binary);
    if (!keyFile.is_open() || !ivFile.is_open()) {
        cerr << "Error opening key/IV file." << endl;
        return false;
    }
    keyFile.read((char*)key, KEY_SIZE / 8);
    ivFile.read((char*)iv, IV_SIZE / 8);
    keyFile.close();
    ivFile.close();
    return true;
}

// Function to encrypt a message
string encryptMessage(const string& plaintext, const unsigned char* key, const unsigned char* iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        cerr << "Error creating cipher context." << endl;
        return "";
    }

    // Initialize encryption context
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        cerr << "Error initializing encryption context." << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    // Encrypt the plaintext
    int len = plaintext.length();
    int ciphertext_len = 0;
    unsigned char ciphertext[len + EVP_MAX_BLOCK_LENGTH];

    if (EVP_EncryptUpdate(ctx, ciphertext, &len, (const unsigned char*)plaintext.c_str(), len) != 1) {
        cerr << "Error encrypting message." << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    ciphertext_len += len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) {
        cerr << "Error finalizing encryption." << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    // Return the ciphertext as a base64 encoded string
    BIO* bio = BIO_new(BIO_s_mem());
    BIO_write(bio, ciphertext, ciphertext_len);
    BIO_flush(bio);
    BUF_MEM* bufferPtr;
    BIO_get_mem_ptr(bio, &bufferPtr);
    string ciphertext_str(bufferPtr->data, bufferPtr->length - 1); // Exclude null terminator
    BIO_free_all(bio);

    return ciphertext_str;
}

// Function to decrypt a message
string decryptMessage(const string& ciphertext, const unsigned char* key, const unsigned char* iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        cerr << "Error creating cipher context." << endl;
        return "";
    }

    // Initialize decryption context
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        cerr << "Error initializing decryption context." << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }

    // Decrypt the ciphertext
    int len = ciphertext.length();
    int plaintext_len = 0;
    unsigned char plaintext[len + EVP_MAX_BLOCK_LENGTH];

    if (EVP_DecryptUpdate(ctx, plaintext, &len, (const unsigned char*)ciphertext.c_str(), len) != 1) {
        cerr << "Error decrypting message." << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    plaintext_len += len;

    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) {
        cerr << "Error finalizing decryption." << endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    // Return the plaintext as a string
    return string((char*)plaintext, plaintext_len);
}

int main() {
    int choice;
    unsigned char key[KEY_SIZE / 8];
    unsigned char iv[IV_SIZE / 8];

    while (true) {
        cout << "
Choose an option:" << endl;
        cout << "1. Generate a new key" << endl;
        cout << "2. Encrypt a message" << endl;
        cout << "3. Decrypt a message" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                generateKeyAndIV();
                break;
            case 2: {
                if (!loadKeyAndIV(key, iv)) {
                    break;
                }
                cin.ignore(); // Consume newline
                cout << "Enter the message to encrypt: ";
                string plaintext;
                getline(cin, plaintext);
                string ciphertext = encryptMessage(plaintext, key, iv);
                cout << "Ciphertext (Base64): " << ciphertext << endl;
                break;
            }
            case 3: {
                if (!loadKeyAndIV(key, iv)) {
                    break;
                }
                cin.ignore(); // Consume newline
                cout << "Enter the ciphertext (Base64) to decrypt: ";
                string ciphertext;
                getline(cin, ciphertext);
                string plaintext = decryptMessage(ciphertext, key, iv);
                cout << "Plaintext: " << plaintext << endl;
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}