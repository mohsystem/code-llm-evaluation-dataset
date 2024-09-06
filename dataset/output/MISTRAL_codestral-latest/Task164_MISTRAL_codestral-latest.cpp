#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::string> lastNameLenSort(std::vector<std::string> names) {
    auto lastName = [](const std::string& name) {
        std::istringstream iss(name);
        std::string word;
        std::string last;
        while (iss >> word) {
            last = word;
        }
        return last;
    };

    std::sort(names.begin(), names.end(), [&lastName](const std::string& a, const std::string& b) {
        if (lastName(a).length() != lastName(b).length()) {
            return lastName(a).length() < lastName(b).length();
        } else {
            return lastName(a) < lastName(b);
        }
    });

    return names;
}

int main() {
    std::vector<std::string> names = {"Jennifer Figueroa", "Heather Mcgee", "Amanda Schwartz", "Nicole Yoder", "Melissa Hoffman"};
    names = lastNameLenSort(names);
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    return 0;
}