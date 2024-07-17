#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("password.txt");
    if(!file) {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string storedPassword;
    getline(file, storedPassword);
    file.close();

    string enteredPassword;
    cout << "Enter your password: ";
    cin >> enteredPassword;

    bool isMatch = storedPassword.length() == enteredPassword.length();
    
    for(size_t i = 0; i < storedPassword.length() && isMatch; ++i) {
        isMatch &= storedPassword[i] == enteredPassword[i];
    }

    if(isMatch) {
        cout << "Password match" << endl;
    } else {
        cout << "Password does not match" << endl;
    }

    return 0;
}