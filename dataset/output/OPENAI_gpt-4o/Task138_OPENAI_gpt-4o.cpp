#include <iostream>
#include <set>
#include <string>

class User {
    std::string username;
    std::set<std::string> permissions;

public:
    User(const std::string& uname) : username(uname) {}
    
    void addPermission(const std::string& permission) {
        permissions.insert(permission);
    }

    bool hasPermission(const std::string& permission) {
        return permissions.find(permission) != permissions.end();
    }
};

int main() {
    User admin("admin");
    admin.addPermission("read");
    admin.addPermission("write");
    std::cout << "Admin has 'read' permission: " << std::boolalpha << admin.hasPermission("read") << std::endl;
    std::cout << "Admin has 'delete' permission: " << std::boolalpha << admin.hasPermission("delete") << std::endl;
    return 0;
}