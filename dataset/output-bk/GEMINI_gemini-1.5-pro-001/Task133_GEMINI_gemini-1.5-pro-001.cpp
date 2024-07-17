#include <iostream>
#include <string>

using namespace std;

void resetPassword() {
    string currentPassword, newPassword, confirmPassword;

    while (true) {
        cout << "Enter your current password: ";
        getline(cin, currentPassword);
        if (currentPassword == "password123") {
            break;
        } else {
            cout << "Incorrect password. Please try again." << endl;
        }
    }

    while (true) {
        cout << "Enter your new password: ";
        getline(cin, newPassword);
        cout << "Confirm your new password: ";
        getline(cin, confirmPassword);
        if (newPassword == confirmPassword) {
            cout << "Password reset successful." << endl;
            break;
        } else {
            cout << "Passwords don't match. Please try again." << endl;
        }
    }
}

int main() {
    resetPassword();
    return 0;
}