#include <iostream>
#include <string>
#include <vector>

std::string whoLikesIt(std::vector<std::string> names) {
    if (names.empty()) return "no one likes this";
    if (names.size() == 1) return names[0] + " likes this";
    if (names.size() == 2) return names[0] + " and " + names[1] + " like this";
    if (names.size() == 3) return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
}

int main() {
    std::vector<std::string> names1;
    std::vector<std::string> names2 = {"Peter"};
    std::vector<std::string> names3 = {"Jacob", "Alex"};
    std::vector<std::string> names4 = {"Max", "John", "Mark"};
    std::vector<std::string> names5 = {"Alex", "Jacob", "Mark", "Max"};
    std::cout << whoLikesIt(names1) << std::endl;
    std::cout << whoLikesIt(names2) << std::endl;
    std::cout << whoLikesIt(names3) << std::endl;
    std::cout << whoLikesIt(names4) << std::endl;
    std::cout << whoLikesIt(names5) << std::endl;
    return 0;
}