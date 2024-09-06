#include <iostream>
#include <fstream>
#include <string>
#include <openssl/sha.h>

using namespace std;

string hashPassword(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.length());
    SHA256_Final(hash, &sha256);

    string hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashedPassword += to_string(static_cast<int>(hash[i]));
    }

    return hashedPassword;
}

void signup() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << ":" << hashPassword(password) << endl;
        file.close();
        cout << "Signup successful!" << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Signup" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            signup();
        } else if (choice == 2) {
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}