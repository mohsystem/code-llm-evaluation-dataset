#include <iostream>
#include <string>
#include <map>

using namespace std;

class AuthenticationSystem {
private:
    map<string, string> users;

public:
    AuthenticationSystem() {
        users["admin"] = "password123";
        users["user"] = "password456";
    }

    bool authenticate(string username, string password) {
        return users.count(username) && users[username] == password;
    }
};

int main() {
    AuthenticationSystem auth;
    string username, password;

    cout << "Enter username: ";
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    if (auth.authenticate(username, password)) {
        cout << "Authentication successful!" << endl;
    } else {
        cout << "Invalid credentials!" << endl;
    }

    return 0;
}