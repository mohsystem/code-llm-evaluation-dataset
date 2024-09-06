
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>

class PermissionManager {
private:
    std::unordered_map<std::string, std::string> users;
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
        users[username] = role;
    }

    void removeUser(const std::string& username) {
        users.erase(username);
    }

    void changeUserRole(const std::string& username, const std::string& newRole) {
        if (users.find(username) == users.end()) {
            throw std::invalid_argument("User not found");
        }
        if (roles.find(newRole) == roles.end()) {
            throw std::invalid_argument("Invalid role");
        }
        users[username] = newRole;
    }

    bool checkPermission(const std::string& username, const std::string& permission) {
        if (users.find(username) == users.end()) {
            return false;
        }
        const std::string& userRole = users[username];
        const std::vector<std::string>& rolePermissions = roles[userRole];
        return std::find(rolePermissions.begin(), rolePermissions.end(), permission) != rolePermissions.end();
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& user : users) {
            file << user.first << "," << user.second << std::endl;
        }
        file.close();
    }

    void loadFromFile(const std::string& filename) {
        users.clear();
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string username, role;
            if (std::getline(iss, username, ',') && std::getline(iss, role)) {
                users[username] = role;
            }
        }
        file.close();
    }
};

int main() {
    PermissionManager pm;

    pm.addUser("alice", "admin");
    pm.addUser("bob", "editor");
    pm.addUser("charlie", "viewer");

    std::cout << pm.checkPermission("alice", "manage_users") << std::endl;  // 1
    std::cout << pm.checkPermission("bob", "write") << std::endl;  // 1
    std::cout << pm.checkPermission("charlie", "delete") << std::endl;  // 0

    pm.changeUserRole("bob", "admin");
    std::cout << pm.checkPermission("bob", "manage_users") << std::endl;  // 1

    pm.removeUser("charlie");
    std::cout << pm.checkPermission("charlie", "read") << std::endl;  // 0

    pm.saveToFile("permissions.txt");
    pm.loadFromFile("permissions.txt");

    return 0;
}
