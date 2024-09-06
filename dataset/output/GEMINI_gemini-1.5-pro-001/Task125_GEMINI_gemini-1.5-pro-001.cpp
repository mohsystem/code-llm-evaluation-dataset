#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    unordered_map<string, vector<string>> roles = {
        {"admin", {"resource1", "resource2", "resource3"}},
        {"editor", {"resource2", "resource3"}},
        {"viewer", {"resource3"}}
    };

    string userRole;
    cout << "Enter your role (admin, editor, viewer): ";
    cin >> userRole;

    if (roles.find(userRole) != roles.end()) {
        cout << "Available resources for " << userRole << ":" << endl;
        for (const string& resource : roles[userRole]) {
            cout << resource << endl;
        }
    } else {
        cout << "Invalid role." << endl;
    }

    return 0;
}