#include <iostream>
#include <string>
#include <unordered_map>
#include <openssl/sha.h>

using namespace std;

unordered_map<string, string> users;

string hashPassword(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    string hashedPassword;
    hashedPassword.reserve(SHA256_DIGEST_LENGTH * 2);
    for (unsigned char byte : hash) {
        hashedPassword.append(1, "0123456789abcdef"[byte / 16]);
        hashedPassword.append(1, "0123456789abcdef"[byte % 16]);
    }

    return hashedPassword;
}

void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Username already exists!" << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    string hashedPassword = hashPassword(password);
    users[username] = hashedPassword;

    cout << "User registered successfully!" << endl;
}

void loginUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    if (users.find(username) == users.end()) {
        cout << "Invalid username or password!" << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    string hashedPassword = hashPassword(password);

    if (hashedPassword == users[username]) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password!" << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}