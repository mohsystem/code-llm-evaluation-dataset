#include <iostream>
#include <vector>
#include <string>

std::string likes(const std::vector<std::string>& names) {
    int n = names.size();
    switch (n) {
        case 0: return "no one likes this";
        case 1: return names[0] + " likes this";
        case 2: return names[0] + " and " + names[1] + " like this";
        case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default: return names[0] + ", " + names[1] + " and " + std::to_string(n - 2) + " others like this";
    }
}

int main() {
    std::cout << likes({}) << std::endl;
    std::cout << likes({"Peter"}) << std::endl;
    std::cout << likes({"Jacob", "Alex"}) << std::endl;
    std::cout << likes({"Max", "John", "Mark"}) << std::endl;
    std::cout << likes({"Alex", "Jacob", "Mark", "Max"}) << std::endl;
    return 0;
}