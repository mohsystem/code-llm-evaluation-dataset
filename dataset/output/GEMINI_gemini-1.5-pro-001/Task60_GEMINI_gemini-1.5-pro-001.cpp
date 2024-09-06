#include <string>

std::string expandedForm(int num) {
    std::string numStr = std::to_string(num);
    int length = numStr.length();
    std::string result = "";
    for (int i = 0; i < length; i++) {
        char digit = numStr[i];
        if (digit != '0') {
            if (!result.empty()) {
                result += " + ";
            }
            result += digit;
            for (int j = i + 1; j < length; j++) {
                result += '0';
            }
        }
    }
    return result;
}