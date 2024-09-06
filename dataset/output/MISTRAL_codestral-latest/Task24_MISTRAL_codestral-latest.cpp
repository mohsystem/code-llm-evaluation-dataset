#include <regex>

bool validate_pin(std::string pin) {
    return (pin.length() == 4 || pin.length() == 6) && std::regex_match(pin, std::regex("\\d+"));
}