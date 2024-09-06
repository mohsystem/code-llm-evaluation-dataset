#include <string>
#include <vector>

class Kata {
public:
    static std::string expandedForm(int num) {
        std::string numStr = std::to_string(num);
        std::vector<std::string> result;
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr[i] != '0') {
                std::string temp = "";
                temp += numStr[i];
                for (int j = 0; j < numStr.length() - i - 1; j++) {
                    temp += "0";
                }
                result.push_back(temp);
            }
        }
        std::string res = "";
        for (int i = 0; i < result.size(); i++) {
            res += result[i];
            if (i != result.size() - 1) {
                res += " + ";
            }
        }
        return res;
    }
};