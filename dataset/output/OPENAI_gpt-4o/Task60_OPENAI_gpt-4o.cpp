#include <iostream>
#include <string>
#include <vector>

std::string expandedForm(int num) {
    std::string numStr = std::to_string(num);
    int length = numStr.length();
    std::vector<std::string> result;
    for (int i = 0; i < length; ++i) {
        if (numStr[i] != '0') {
            result.push_back(numStr[i] + std::string(length - i - 1, '0'));
        }
    }
    std::string final_result;
    for (size_t i = 0; i < result.size(); ++i) {
        final_result += result[i];
        if (i != result.size() - 1) {
            final_result += " + ";
        }
    }
    return final_result;
}

int main() {
    std::cout << expandedForm(12) << std::endl;    // Should return "10 + 2"
    std::cout << expandedForm(42) << std::endl;    // Should return "40 + 2"
    std::cout << expandedForm(70304) << std::endl; // Should return "70000 + 300 + 4"
    return 0;
}