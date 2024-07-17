
#include <string>

bool validatePin(std::string pin) {
    if (pin.length() != 4 && pin.length() != 6) return false;
    
    for (char c : pin) {
        if (!isdigit(c)) return false;
    }
    
    return true;
}
