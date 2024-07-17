#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::string> lastNameLensort(std::vector<std::string> &names) {
    std::sort(names.begin(), names.end(), [](const std::string &a, const std::string &b) {
        std::istringstream issA(a), issB(b);
        std::string firstNameA, lastNameA, firstNameB, lastNameB;
        issA >> firstNameA >> lastNameA;
        issB >> firstNameB >> lastNameB;
        if (lastNameA.length() != lastNameB.length()) {
            return lastNameA.length() < lastNameB.length();
        } else {
            return lastNameA < lastNameB;
        }
    });
    return names;
}

int main() {
    std::vector<std::string> names = {
        "Jennifer Figueroa",
        "Heather Mcgee",
        "Amanda Schwartz",
        "Nicole Yoder",
        "Melissa Hoffman"
    };

    std::vector<std::string> sortedNames = lastNameLensort(names);

    for (const std::string &name : sortedNames) {
        std::cout << name << std::endl;
    }
    return 0;
}