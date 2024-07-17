
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::unordered_map<std::string, std::vector<std::string>> accessMatrix = {
    {"admin", {"server", "database", "network"}},
    {"developer", {"database", "codebase"}},
    {"tester", {"codebase", "testbed"}},
    {"user", {"application"}}
};

bool checkAccess(const std::string& userRole, const std::string& resource) {
    auto it = accessMatrix.find(userRole);
    if (it != accessMatrix.end()) {
        const auto& allowedResources = it->second;
        return std::find(allowedResources.begin(), allowedResources.end(), resource) != allowedResources.end();
    }
    return false;
}

int main() {
    std::string userRole, resource;
    
    std::cout << "Enter your role: ";
    std::cin >> userRole;
    
    std::cout << "Enter the resource you want to access: ";
    std::cin >> resource;
    
    std::transform(userRole.begin(), userRole.end(), userRole.begin(), ::tolower);
    std::transform(resource.begin(), resource.end(), resource.begin(), ::tolower);
    
    if (checkAccess(userRole, resource)) {
        std::cout << "Access granted to " << resource << std::endl;
    } else {
        std::cout << "Access denied" << std::endl;
    }
    
    return 0;
}
