#include <string>
#include <sstream>

std::string expandedForm(int num) {
    std::stringstream ss;
    std::string numStr = std::to_string(num);
    for (int i = 0; i < numStr.length(); i++) {
        char digit = numStr[i];
        if (digit != '0') {
            if (ss.tellp() > 0) {
                ss << " + ";
            }
            ss << digit;
            for (int j = 0; j < numStr.length() - i - 1; j++) {
                ss << "0";
            }
        }
    }
    return ss.str();
}