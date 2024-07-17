
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <algorithm>

class User {
public:
    std::string username;
    std::string role;
    std::vector<std::string> permissions;

    User(const std::string& username, const std::string& role)
        : username(username), role(role) {}
};

class PermissionManager {
private:
    std::unordered_map<std::string, User> users;
    std::unordered_map<std::string, std::vector<std::string>> roles;

public:
    PermissionManager() {
        roles["admin"] = {"read", "write", "delete", "manage_users"};
        roles["editor"] = {"read", "write"};
        roles["viewer"] = {"read"};
    }

    void addUser(const std::string& username, const std::string& role) {
        if (roles.find(role) == roles.end()) {
            throw std::invalid_argument("Invalid role");
        }
        User user(username, role);
        user.permissions = roles[role];
        users[username] = user;
    }

    void removeUser(const std::string& username) {
        users.erase(username);
    }

    void changeUserRole(const std::string& username, const std::string& newRole) {
        if (users.find(username) != users.end() && roles.find(newRole) != roles.end()) {
            users[username].role = newRole;
            users[username].permissions = roles[newRole];
        }
    }

    bool checkPermission(const std::string& username, const std::string& permission) {
        if (users.find(username) != users.end()) {
            return std::find(users[username].permissions.begin(),
                             users[username].permissions.end(),
                             permission) != users[username].permissions.end();
        }
        return false;
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& pair : users) {
            const User& user = pair.second;
            file << user.username << "," << user.role << ",";
            for (size_t i = 0; i < user.permissions.size(); ++i) {
                file << user.permissions[i];
                if (i < user.permissions.size() - 1) file << ":";
            }
            file << std::endl;
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string username, role;
            std::getline(iss, username, \',\');
            std::getline(iss, role, \',\');
            addUser(username, role);
        }
    }
};

int main() {
    PermissionManager pm;

    pm.addUser("alice", "admin");
    pm.addUser("bob", "editor");
    pm.addUser("charlie", "viewer");

    std::cout << pm.checkPermission("alice", "manage_users") << std::endl; // 1
    std::cout << pm.checkPermission("bob", "write") << std::endl; // 1
    std::cout << pm.checkPermission("charlie", "delete") << std::endl; // 0

    pm.changeUserRole("bob", "admin");
    std::cout << pm.checkPermission("bob", "manage_users") << std::endl; // 1

    pm.removeUser("charlie");
    std::cout << pm.checkPermission("charlie", "read") << std::endl; // 0

    pm.saveToFile("permissions.txt");
    PermissionManager newPm;
    newPm.loadFromFile("permissions.txt");
    std::cout << newPm.checkPermission("alice", "manage_users") << std::endl; // 1

    return 0;
}
