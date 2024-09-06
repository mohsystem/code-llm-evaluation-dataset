// C++

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> resources = {
        {"A", "Resource A"},
        {"B", "Resource B"},
        {"C", "Resource C"}
    };

    std::string userInput;
    std::cout << "Enter a key to access a resource: ";
    std::cin >> userInput;

    if (resources.find(userInput) != resources.end()) {
        std::cout << "Access granted to: " << resources[userInput] << std::endl;
    } else {
        std::cout << "Access denied. Invalid key." << std::endl;
    }

    return 0;
}