
#include <iostream>
#include <string>

class Accumul {
public:
    static std::string accum(const std::string& s) {
        std::string result;
        for (size_t i = 0; i < s.length(); i++) {
            result += std::toupper(s[i]);
            for (size_t j = 0; j < i; j++) {
                result += std::tolower(s[i]);
            }
            if (i < s.length() - 1) {
                result += "-";
            }
        }
        return result;
    }
};

int main() {
    std::cout << Accumul::accum("abcd") << std::endl;
    std::cout << Accumul::accum("RqaEzty") << std::endl;
    std::cout << Accumul::accum("cwAt") << std::endl;
    return 0;
}
