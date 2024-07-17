#include <string>
#include <sstream>

std::string expandedForm(int num) {
    std::string str = std::to_string(num);
    std::string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '0') {
            result += str[i];
            for (int j = i + 1; j < str.length(); j++) {
                result += "0";
            }
            if (i < str.length() - 1) {
                result += " + ";
            }
        }
    }
    return result;
}