#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool authenticate(const string& username, const string& password, 
                 const unordered_map<string, string>& database) {
    if (database.count(username) && database.at(username) == password) {
        return true;
    }
    return false;
}

int main() {
    unordered_map<string, string> userDatabase = {
        {"user1", "password123"},
        {"john_doe", "securepassword"}
    };

    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (authenticate(username, password, userDatabase)) {
        cout << "Authentication successful. Welcome, " << username << "!" << endl;
    } else {
        cout << "Authentication failed. Invalid username or password." << endl;
    }

    return 0;
}