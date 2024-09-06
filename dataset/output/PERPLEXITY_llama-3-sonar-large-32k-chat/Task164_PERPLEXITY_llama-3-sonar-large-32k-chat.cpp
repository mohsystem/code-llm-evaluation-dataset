#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> lastNameLensort(std::vector<std::string> names) {
    std::sort(names.begin(), names.end(), [](const std::string& s1, const std::string& s2) {
        size_t space1 = s1.find(' ');
        size_t space2 = s2.find(' ');
        std::string lastName1 = s1.substr(space1 + 1);
        std::string lastName2 = s2.substr(space2 + 1);
        if (lastName1.length() != lastName2.length()) {
            return lastName1.length() < lastName2.length();
        } else {
            return lastName1 < lastName2;
        }
    });
    return names;
}