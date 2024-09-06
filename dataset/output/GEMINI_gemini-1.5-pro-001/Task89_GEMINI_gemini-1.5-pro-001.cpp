#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkPassword(const string& storedPassword) {
    string enteredPassword;
    cout << "Enter password: ";
    cin >> enteredPassword;
    if (enteredPassword.length() != storedPassword.length()) {
        return false;
    }
    for (size_t i = 0; i < storedPassword.length(); ++i) {
        if (storedPassword[i] != enteredPassword[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream file("password.txt");
    if (!file.is_open()) {
        cerr << "Password file not found. Please create 'password.txt'." << endl;
        return 1;
    }

    string storedPassword;
    getline(file, storedPassword);
    file.close();

    if (checkPassword(storedPassword)) {
        cout << "Passwords match." << endl;
    } else {
        cout << "Passwords do not match." << endl;
    }

    return 0;
}