
#include <iostream>
#include <vector>
#include <string>

std::string who_likes_it(const std::vector<std::string>& names) {
    switch (names.size()) {
        case 0: return "no one likes this";
        case 1: return names[0] + " likes this";
        case 2: return names[0] + " and " + names[1] + " like this";
        case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}

int main() {
    std::cout << who_likes_it({}) << std::endl;
    std::cout << who_likes_it({"Peter"}) << std::endl;
    std::cout << who_likes_it({"Jacob", "Alex"}) << std::endl;
    std::cout << who_likes_it({"Max", "John", "Mark"}) << std::endl;
    std::cout << who_likes_it({"Alex", "Jacob", "Mark", "Max"}) << std::endl;
    return 0;
}
