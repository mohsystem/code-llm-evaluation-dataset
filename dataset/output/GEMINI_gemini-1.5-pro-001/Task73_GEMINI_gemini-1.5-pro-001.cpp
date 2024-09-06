#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPasswordValid(const string& password) {
    if (password.length() < 8) {
        return false;
    }
    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char ch : password) {
        if (isupper(ch)) {
            hasUpper = true;
        } else if (islower(ch)) {
            hasLower = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        }
    }
    return hasUpper && hasLower && hasDigit;
}

int main() {
    string password;
    cout << "Enter the password: ";
    cin >> password;

    if (isPasswordValid(password)) {
        cout << "Valid password" << endl;
    } else {
        cout << "Invalid password" << endl;
    }

    return 0;
}