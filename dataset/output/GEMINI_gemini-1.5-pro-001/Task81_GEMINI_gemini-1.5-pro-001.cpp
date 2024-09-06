#include <iostream>
#include <fstream>
#include <string>
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std;

string calculateCertificateHash(const string& filename, const string& hash_algorithm) {
    unsigned char hash[SHA256_DIGEST_LENGTH]; // Or MD5_DIGEST_LENGTH if needed
    const int bufferSize = 32768;
    unsigned char buffer[bufferSize];
    ifstream file(filename, ios::in | ios::binary);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }

    // Select the hashing algorithm
    const EVP_MD* (*hash_function)(void) = nullptr;
    if (hash_algorithm == "sha256") {
        hash_function = EVP_sha256;
    } else if (hash_algorithm == "md5") {
        hash_function = EVP_md5;
    } else {
        cerr << "Unsupported hash algorithm: " << hash_algorithm << endl;
        return "";
    }

    EVP_MD_CTX* hashContext = EVP_MD_CTX_new();
    EVP_DigestInit_ex(hashContext, hash_function(), nullptr);

    while (file) {
        file.read((char*)buffer, bufferSize);
        EVP_DigestUpdate(hashContext, buffer, file.gcount());
    }

    EVP_DigestFinal_ex(hashContext, hash, nullptr);
    EVP_MD_CTX_free(hashContext);

    // Convert the hash to a hexadecimal string
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) { // Or MD5_DIGEST_LENGTH if needed
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool verifyCertificateHash(const string& filename, const string& expected_hash, const string& hash_algorithm) {
    string calculated_hash = calculateCertificateHash(filename, hash_algorithm);
    return calculated_hash == expected_hash;
}

int main() {
    string filename, expected_hash, hash_algorithm;

    cout << "Enter the path to the SSL certificate: ";
    cin >> filename;
    cout << "Enter the expected hash value: ";
    cin >> expected_hash;
    cout << "Enter the hash algorithm used (e.g., sha256, md5): ";
    cin >> hash_algorithm;

    if (verifyCertificateHash(filename, expected_hash, hash_algorithm)) {
        cout << "Certificate hash matches!" << endl;
    } else {
        cout << "Certificate hash does not match." << endl;
    }

    return 0;
}