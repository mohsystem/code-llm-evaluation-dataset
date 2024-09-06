#include <iostream>
#include <string>

using namespace std;

string checkPassword(string password) {
    string adminPassword = "admin123";
    if (password == adminPassword) {
        return "Password is valid";
    } else {
        return "Password is invalid";
    }
}

int main() {
    string inputPassword;
    cout << "Enter the admin password: ";
    getline(cin, inputPassword);

    cout << checkPassword(inputPassword) << endl;

    return 0;
}