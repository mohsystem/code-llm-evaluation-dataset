#include <iostream>
#include <vector>
#include <string>

std::string whoLikesIt(const std::vector<std::string>& names) {
    int count = names.size();

    if (count == 0) {
        return "no one likes this";
    } else if (count == 1) {
        return names[0] + " likes this";
    } else if (count == 2) {
        return names[0] + " and " + names[1] + " like this";
    } else if (count == 3) {
        return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    } else {
        return names[0] + ", " + names[1] + " and " + std::to_string(count - 2) + " others like this";
    }
}

int main() {
    std::vector<std::string> names = {"Alex", "Jacob", "Mark", "Max"};
    std::cout << whoLikesIt(names) << std::endl;
    return 0;
}