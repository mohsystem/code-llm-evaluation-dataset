#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <openssl/sha.h>

using namespace std;

string hash_password(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    string hashed_password;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashed_password += to_string(static_cast<unsigned int>(hash[i]));
    }
    return hashed_password;
}

void create_user(const string& username, const string& password) {
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << ":" << hash_password(password) << endl;
        file.close();
        cout << "User '" << username << "' created successfully!" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}

bool authenticate_user(const string& username, const string& password) {
    ifstream file("users.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            size_t pos = line.find(':');
            if (pos != string::npos) {
                string u = line.substr(0, pos);
                string h = line.substr(pos + 1);
                if (u == username && h == hash_password(password)) {
                    cout << "Authentication successful. Welcome!" << endl;
                    file.close();
                    return true;
                }
            }
        }
        file.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }
    cout << "Authentication failed. Invalid username or password." << endl;
    return false;
}

int main() {
    int choice;
    string username, password;

    while (true) {
        cout << "1. Create user" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                create_user(username, password);
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                authenticate_user(username, password);
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}