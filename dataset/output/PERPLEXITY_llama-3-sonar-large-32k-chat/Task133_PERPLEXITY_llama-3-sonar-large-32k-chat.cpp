#include <iostream>
#include <string>

using namespace std;

int main() {
    string username, oldPassword, newPassword, confirmPassword;

    cout << "Enter your username: ";
    getline(cin, username);

    cout << "Enter your old password: ";
    getline(cin, oldPassword);

    cout << "Enter your new password: ";
    getline(cin, newPassword);

    cout << "Confirm your new password: ";
    getline(cin, confirmPassword);

    if (newPassword == confirmPassword) {
        cout << "Password reset successfully!" << endl;
    } else {
        cout << "New password and confirm password do not match. Try again!" << endl;
    }

    return 0;
}