// C++
#include <iostream>
#include <vector>
#include <algorithm>

class User {
private:
    std::string name;
    std::vector<std::string> permissions;

public:
    User(std::string name, std::vector<std::string> permissions) {
        this->name = name;
        this->permissions = permissions;
    }

    bool hasPermission(std::string permission) {
        return std::find(permissions.begin(), permissions.end(), permission) != permissions.end();
    }
};

// Example usage
int main() {
    User user("John", {"read", "write"});
    std::cout << user.hasPermission("read") << std::endl;  // 1 (true)
    std::cout << user.hasPermission("execute") << std::endl;  // 0 (false)
    return 0;
}