#include <cctype>
#include <string>

bool validate_pin(const std::string& pin) {
    int len = pin.length();
    if (len != 4 && len != 6)
        return false;
    for (char c : pin)
        if (!std::isdigit(c))
            return false;
    return true;
}