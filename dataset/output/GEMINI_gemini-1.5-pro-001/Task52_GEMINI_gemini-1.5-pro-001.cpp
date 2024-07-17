#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptDecrypt(string &data, string key) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] ^= key[i % key.size()]; // XOR encryption/decryption
    }
}

int main() {
    string filename, key;

    cout << "Enter filename: ";
    cin >> filename;

    cout << "Enter encryption key: ";
    cin >> key;

    // Read file content into a string
    ifstream inputFile(filename, ios::binary);
    string fileData((istreambuf_iterator<char>(inputFile)), 
                      istreambuf_iterator<char>());
    inputFile.close();

    // Encrypt the data
    encryptDecrypt(fileData, key);

    // Write encrypted data to a new file
    ofstream encryptedFile(filename + ".enc", ios::binary);
    encryptedFile << fileData;
    encryptedFile.close();

    cout << "File encrypted successfully.
";

    // Decrypt (for demonstration - you'd usually separate these)
    string decryptedData = fileData; // Start with encrypted data
    encryptDecrypt(decryptedData, key); 

    ofstream decryptedFile(filename + ".dec", ios::binary);
    decryptedFile << decryptedData;
    decryptedFile.close();

    cout << "File decrypted successfully.
";

    return 0;
}