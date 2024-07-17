#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValidAdminPassword(const string& password);

int main() {
    string password;
    cout << "Enter password: ";
    getline(cin, password);

    if (isValidAdminPassword(password)) {
        cout << "Valid password" << endl;
    } else {
        cout << "Invalid password" << endl;
    }
    return 0;
}

bool isValidAdminPassword(const string& password) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    if (password.length() < 10) {
        return false;
    }
    for (char c : password) {
        if (isupper(c)) {
            hasUpper = true;
        } else if (islower(c)) {
            hasLower = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (string("!@#$%^&*()").find(c) != string::npos) {
            hasSpecial = true;
        }
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}