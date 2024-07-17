#include <iostream>
#include <set>
#include <string>

class User {
    private:
        std::string username;
        std::set<std::string> permissions;

    public:
        User(std::string username) : username(username) {}

        void addPermission(std::string permission) {
            permissions.insert(permission);
        }

        bool hasPermission(std::string permission) {
            return permissions.find(permission) != permissions.end();
        }

        std::string getUsername() {
            return username;
        }
};

int main() {
    User user("john_doe");
    user.addPermission("read");
    user.addPermission("write");

    std::cout << "User " << user.getUsername() << " has read permission: " << user.hasPermission("read") << std::endl;
    std::cout << "User " << user.getUsername() << " has write permission: " << user.hasPermission("write") << std::endl;
    std::cout << "User " << user.getUsername() << " has delete permission: " << user.hasPermission("delete") << std::endl;

    return 0;
}