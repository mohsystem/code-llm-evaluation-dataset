#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::string> lastNameLenSort(std::vector<std::string> names) {
    std::sort(names.begin(), names.end(), [](const std::string& a, const std::string& b) {
        std::istringstream issA(a);
        std::istringstream issB(b);
        std::string lastNameA, lastNameB;
        issA >> std::string() >> lastNameA;
        issB >> std::string() >> lastNameB;
        if (lastNameA.length() != lastNameB.length()) {
            return lastNameA.length() < lastNameB.length();
        } else {
            return lastNameA < lastNameB;
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