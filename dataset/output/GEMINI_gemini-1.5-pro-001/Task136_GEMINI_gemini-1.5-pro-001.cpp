#include <iostream>
#include <string>

using namespace std;

bool authenticate(const string& username, const string& password) {
    // Check if the provided username and password match a predefined set
    string validUsername = "user";
    string validPassword = "password";
    return username == validUsername && password == validPassword;
}

int main() {
    // Get user credentials
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    // Authenticate user
    if (authenticate(username, password)) {
        cout << "Authentication successful. Welcome!" << endl;
    } else {
        cout << "Authentication failed. Invalid username or password." << endl;
    }

    return 0;
}