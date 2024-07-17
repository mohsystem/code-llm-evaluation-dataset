
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> lastNameLenSort(std::vector<std::string> names) {
    std::sort(names.begin(), names.end(), [](const std::string& a, const std::string& b) {
        auto aLastSpace = a.find_last_of(\' \');
        auto bLastSpace = b.find_last_of(\' \');
        std::string aLastName = a.substr(aLastSpace + 1);
        std::string bLastName = b.substr(bLastSpace + 1);
        
        if (aLastName.length() != bLastName.length()) {
            return aLastName.length() < bLastName.length();
        }
        return aLastName < bLastName;
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
    
    auto sorted = lastNameLenSort(names);
    
    for (const auto& name : sorted) {
        std::cout << name << std::endl;
    }
    
    return 0;
}
