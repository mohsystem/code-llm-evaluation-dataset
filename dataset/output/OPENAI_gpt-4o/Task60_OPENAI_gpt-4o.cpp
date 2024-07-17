#include <iostream>
#include <string>

std::string expandedForm(int num) {
    std::string result = "";
    std::string numStr = std::to_string(num);
    int length = numStr.length();
    
    for (int i = 0; i < length; i++) {
        if (numStr[i] != '0') {
            result += numStr[i];
            for (int j = i + 1; j < length; j++) {
                result += "0";
            }
            if (i < length - 1) {
                result += " + ";
            }
        }
    }

    if (result.substr(result.size() - 3) == " + ") {
        result = result.substr(0, result.size() - 3);
    }

    return result;
}

int main() {
    std::cout << expandedForm(12) << std::endl;   // Should return "10 + 2"
    std::cout << expandedForm(42) << std::endl;   // Should return "40 + 2"
    std::cout << expandedForm(70304) << std::endl; // Should return "70000 + 300 + 4"
    return 0;
}