#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string username, password, confirmPassword;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    cout << "Confirm your password: ";
    cin >> confirmPassword;

    if (password == confirmPassword) {
        ofstream outfile;
        outfile.open("users.txt", ios::app); 
        outfile << username << ":" << password << endl;
        outfile.close();
        cout << "Signup successful!" << endl;
    } else {
        cout << "Passwords don't match. Please try again." << endl;
    }

    return 0;
}