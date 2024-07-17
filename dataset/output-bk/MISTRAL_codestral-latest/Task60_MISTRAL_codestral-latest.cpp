// C++
#include <string>
#include <sstream>

std::string expandedForm(int num) {
    std::stringstream ss;
    int digits[] = {10000, 1000, 100, 10, 1};
    for (int i = 0; i < 5; i++) {
        if (num >= digits[i]) {
            int count = num / digits[i];
            ss << count * digits[i];
            num -= count * digits[i];
            if (num > 0) {
                ss << " + ";
            }
        }
    }
    return ss.str();
}