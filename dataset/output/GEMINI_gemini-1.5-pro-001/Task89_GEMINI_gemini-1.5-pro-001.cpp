#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string storedPassword, enteredPassword;
    ifstream file("password.txt");

    cout << "Enter password: ";
    getline(cin, enteredPassword);

    if (file.is_open()) {
        getline(file, storedPassword);
        file.close();

        if (storedPassword == enteredPassword) {
            cout << "Password matches." << endl;
        } else {
            cout << "Incorrect password." << endl;
        }
    } else {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    return 0;
}