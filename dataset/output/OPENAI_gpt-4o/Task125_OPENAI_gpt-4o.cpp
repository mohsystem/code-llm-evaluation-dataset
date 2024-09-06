#include <iostream>
#include <unordered_map>

std::string accessResource(const std::string &user) {
    std::unordered_map<std::string, std::string> resources = {
        {"admin", "Access to administrative resources granted."},
        {"user", "Access to user resources granted."},
        {"guest", "Access to guest resources granted."}
    };

    auto it = resources.find(user);
    if (it != resources.end()) {
        return it->second;
    } else {
        return "No resources available for this user role";
    }
}

int main() {
    std::string userRole;
    std::cout << "Enter user role (admin/user/guest): ";
    std::cin >> userRole;

    std::string result = accessResource(userRole);
    std::cout << result << std::endl;

    return 0;
}