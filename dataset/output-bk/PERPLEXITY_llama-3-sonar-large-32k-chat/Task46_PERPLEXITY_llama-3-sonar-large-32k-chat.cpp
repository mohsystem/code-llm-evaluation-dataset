#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> database;

void registerUser(string name, string email, string password) {
    database[email] = name + ":" + password;
    cout << "User information stored in database:" << endl;
    cout << "Email: " << email << endl;
    cout << "Name: " << name << endl;
    cout << "Password: " << password << endl;
}

int main() {
    string name, email, password;

    cout << "Welcome to the User Registration System!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);

    registerUser(name, email, password);

    cout << "User registered successfully!" << endl;

    return 0;
}