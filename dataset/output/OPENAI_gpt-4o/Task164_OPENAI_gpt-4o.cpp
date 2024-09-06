#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::string> lastNameLensort(std::vector<std::string> &names) {
    auto getLastName = [](const std::string &name) -> std::string {
        std::istringstream ss(name);
        std::string firstName, lastName;
        ss >> firstName >> lastName;
        return lastName;
    };

    std::sort(names.begin(), names.end(), [&](const std::string &a, const std::string &b) {
        std::string lastNameA = getLastName(a);
        std::string lastNameB = getLastName(b);
        if (lastNameA.length() == lastNameB.length()) {
            return lastNameA < lastNameB;
        }
        return lastNameA.length() < lastNameB.length();
    });

    return names;
}

int main() {
    std::vector<std::string> names = {"Jennifer Figueroa", "Heather Mcgee", "Amanda Schwartz", "Nicole Yoder", "Melissa Hoffman"};
    auto result = lastNameLensort(names);
    for (const auto &name : result) {
        std::cout << name << std::endl;
    }
    return 0;
}