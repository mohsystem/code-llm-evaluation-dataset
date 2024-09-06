#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isValidPassword(const string& password) {
    if (password.length() < 8) {
        return false;
    }
    regex pattern("(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).+");
    return regex_search(password, pattern);
}

void resetPassword() {
    string newPassword, confirmPassword;
    while (true) {
        cout << "Enter your new password: ";
        getline(cin, newPassword);
        cout << "Confirm your new password: ";
        getline(cin, confirmPassword);

        if (newPassword == confirmPassword && isValidPassword(newPassword)) {
            cout << "Password reset successfully!" << endl;
            break;
        } else {
            cout << "Invalid password or passwords don't match. Please try again." << endl;
        }
    }
}

int main() {
    resetPassword();
    return 0;
}