#include <iostream>
#include <map>
#include <string>
#include <vector>

class User {
public:
    std::string username;
    std::string password;
    std::vector<std::string> privileges;

    User(std::string username, std::string password, std::vector<std::string> privileges)
        : username(username), password(password), privileges(privileges) {}

    bool hasPrivilege(std::string privilege) {
        for (const auto& p : privileges) {
            if (p == privilege) {
                return true;
            }
        }
        return false;
    }
};

class PermissionManager {
private:
    std::map<std::string, User> users;

public:
    void addUser(std::string username, std::string password, std::vector<std::string> privileges) {
        users[username] = User(username, password, privileges);
    }

    User authenticate(std::string username, std::string password) {
        if (users.find(username) != users.end() && users[username].password == password) {
            return users[username];
        } else {
            return User("", "", {});
        }
    }

    bool checkPrivilege(std::string username, std::string password, std::string privilege) {
        User user = authenticate(username, password);
        if (!user.username.empty() && user.hasPrivilege(privilege)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    PermissionManager manager;
    manager.addUser("admin", "password", {"read", "write", "execute"});
    manager.addUser("user", "password", {"read"});

    std::cout << std::boolalpha << manager.checkPrivilege("admin", "password", "write") << std::endl;  // true
    std::cout << std::boolalpha << manager.checkPrivilege("user", "password", "write") << std::endl;  // false

    return 0;
}