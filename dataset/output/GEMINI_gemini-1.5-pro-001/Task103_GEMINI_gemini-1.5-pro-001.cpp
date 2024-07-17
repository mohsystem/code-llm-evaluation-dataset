#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;

    cout << "Enter password: ";
    cin >> password;

    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long." << endl;
        return 0;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false;

    for (char c : password) {
        if (isupper(c)) {
            hasUpper = true;
        } else if (islower(c)) {
            hasLower = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        }
    }

    if (hasUpper && hasLower && hasDigit) {
        cout << "Strong password." << endl;
    } else {
        cout << "Weak password." << endl;
    }

    return 0;
}