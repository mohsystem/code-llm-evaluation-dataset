#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Permission {
public:
    std::string name;

    Permission(const std::string& name) : name(name) {}
};

class User {
public:
    std::string username;
    std::vector<Permission> permissions;

    User(const std::string& username) : username(username) {}

    void addPermission(const Permission& permission) {
        if (std::find(permissions.begin(), permissions.end(), permission) == permissions.end()) {
            permissions.push_back(permission);
        }
    }

    void removePermission(const Permission& permission) {
        permissions.erase(std::remove(permissions.begin(), permissions.end(), permission), permissions.end());
    }

    bool hasPermission(const std::string& permissionName) const {
        return std::any_of(permissions.begin(), permissions.end(),
                           [&permissionName](const Permission& p) { return p.name == permissionName; });
    }
};

int main() {
    Permission readPermission("read");
    Permission writePermission("write");

    User user1("john_doe");
    user1.addPermission(readPermission);

    User user2("jane_doe");
    user2.addPermission(readPermission);
    user2.addPermission(writePermission);

    std::cout << user1.username << " has read permission: " << user1.hasPermission("read") << std::endl;
    std::cout << user1.username << " has write permission: " << user1.hasPermission("write") << std::endl;

    std::cout << user2.username << " has read permission: " << user2.hasPermission("read") << std::endl;
    std::cout << user2.username << " has write permission: " << user2.hasPermission("write") << std::endl;

    return 0;
}