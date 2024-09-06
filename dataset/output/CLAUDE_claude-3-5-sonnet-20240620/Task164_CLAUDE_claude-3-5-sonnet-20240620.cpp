
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> lastNameLensort(std::vector<std::string> names) {
    std::sort(names.begin(), names.end(), [](const std::string& a, const std::string& b) {
        auto aLast = a.substr(a.find_last_of(' ') + 1);
        auto bLast = b.substr(b.find_last_of(' ') + 1);
        
        if (aLast.length() != bLast.length()) {
            return aLast.length() < bLast.length();
        }
        return aLast < bLast;
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
    
    auto sorted = lastNameLensort(names);
    
    for (const auto& name : sorted) {
        std::cout << name << std::endl;
    }
    
    return 0;
}
