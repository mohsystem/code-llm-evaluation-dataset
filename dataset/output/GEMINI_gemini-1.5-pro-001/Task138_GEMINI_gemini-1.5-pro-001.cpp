#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class User {
public:
    string username;
    vector<string> permissions;

    User(string username) : username(username) {}

    void addPermission(const string& permission) {
        if (find(permissions.begin(), permissions.end(), permission) == permissions.end()) {
            permissions.push_back(permission);
        }
    }

    void removePermission(const string& permission) {
        permissions.erase(remove(permissions.begin(), permissions.end(), permission), permissions.end());
    }

    bool hasPermission(const string& permission) const {
        return find(permissions.begin(), permissions.end(), permission) != permissions.end();
    }
};

int main() {
    unordered_map<string, User> users;

    while (true) {
        cout << "Enter action (create user, add permission, remove permission, check permission, list users, exit): ";
        string action;
        getline(cin, action);

        if (action == "create user") {
            cout << "Enter username: ";
            string username;
            getline(cin, username);
            if (users.find(username) != users.end()) {
                cout << "User already exists." << endl;
            } else {
                users[username] = User(username);
                cout << "User created successfully." << endl;
            }
        } else if (action == "add permission") {
            cout << "Enter username: ";
            string username;
            getline(cin, username);
            if (users.find(username) != users.end()) {
                cout << "Enter permission to add: ";
                string permission;
                getline(cin, permission);
                users[username].addPermission(permission);
                cout << "Permission added successfully." << endl;
            } else {
                cout << "User not found." << endl;
            }
        } else if (action == "remove permission") {
            cout << "Enter username: ";
            string username;
            getline(cin, username);
            if (users.find(username) != users.end()) {
                cout << "Enter permission to remove: ";
                string permission;
                getline(cin, permission);
                users[username].removePermission(permission);
                cout << "Permission removed successfully." << endl;
            } else {
                cout << "User not found." << endl;
            }
        } else if (action == "check permission") {
            cout << "Enter username: ";
            string username;
            getline(cin, username);
            if (users.find(username) != users.end()) {
                cout << "Enter permission to check: ";
                string permission;
                getline(cin, permission);
                if (users[username].hasPermission(permission)) {
                    cout << "User has permission." << endl;
                } else {
                    cout << "User does not have permission." << endl;
                }
            } else {
                cout << "User not found." << endl;
            }
        } else if (action == "list users") {
            if (users.empty()) {
                cout << "No users found." << endl;
            } else {
                for (const auto& pair : users) {
                    cout << pair.first << endl;
                }
            }
        } else if (action == "exit") {
            break;
        } else {
            cout << "Invalid action." << endl;
        }
    }

    return 0;
}