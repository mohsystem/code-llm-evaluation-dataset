#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool compare(const std::string& s1, const std::string& s2) {
    size_t space1 = s1.find(' ');
    size_t space2 = s2.find(' ');
    if (s1.substr(space1 + 1).length() != s2.substr(space2 + 1).length()) {
        return s1.substr(space1 + 1).length() < s2.substr(space2 + 1).length();
    } else {
        return s1.substr(space1 + 1) < s2.substr(space2 + 1);
    }
}

int main() {
    std::vector<std::string> names = {
      "Jennifer Figueroa",
      "Heather Mcgee",
      "Amanda Schwartz",
      "Nicole Yoder",
      "Melissa Hoffman"
    };
    std::sort(names.begin(), names.end(), compare);
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }
    return 0;
}