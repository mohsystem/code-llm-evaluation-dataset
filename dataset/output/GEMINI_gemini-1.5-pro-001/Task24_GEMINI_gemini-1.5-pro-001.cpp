#include <string>
#include <regex>

bool validate_pin(std::string pin) {
  std::regex pattern("^(?:\\d{4}|\\d{6})$");
  return std::regex_match(pin, pattern);
}