
#include <iostream>
#include <string>
#include <vector>

std::string expanded_form(long long num) {
    std::string numStr = std::to_string(num);
    std::vector<std::string> parts;
    
    for (size_t i = 0; i < numStr.length(); ++i) {
        if (numStr[i] != '0') {
            std::string part = std::string(1, numStr[i]);
            part.append(numStr.length() - i - 1, '0');
            parts.push_back(part);
        }
    }
    
    std::string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) {
            result += " + ";
        }
        result += parts[i];
    }
    
    return result;
}

int main() {
    std::cout << expanded_form(12) << std::endl;    // Output: 10 + 2
    std::cout << expanded_form(42) << std::endl;    // Output: 40 + 2
    std::cout << expanded_form(70304) << std::endl; // Output: 70000 + 300 + 4
    return 0;
}
