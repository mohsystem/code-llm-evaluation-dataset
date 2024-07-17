
#include <iostream>
#include <string>

class Kata {
public:
    static std::string expandedForm(long long num) {
        std::string numStr = std::to_string(num);
        std::string result;
        for (size_t i = 0; i < numStr.length(); i++) {
            if (numStr[i] != \'0\') {
                if (!result.empty()) {
                    result += " + ";
                }
                result += numStr[i];
                result += std::string(numStr.length() - i - 1, \'0\');
            }
        }
        return result;
    }
};

int main() {
    std::cout << Kata::expandedForm(12) << std::endl;
    std::cout << Kata::expandedForm(42) << std::endl;
    std::cout << Kata::expandedForm(70304) << std::endl;
    return 0;
}
